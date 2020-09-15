# This dockerfile is meant to cross compile with a x64 machine for a arm64v8 host
# It is using multi stage build:
# * downloader: Download litecoin/bitcoin and qemu binaries needed for c-lightning
# * builder: Cross compile c-lightning dependencies, then c-lightning itself with static linking
# * final: Copy the binaries required at runtime
# The resulting image uploaded to dockerhub will only contain what is needed for runtime.
# From the root of the repository, run "docker build -t yourimage:yourtag -f contrib/linuxarm64v8.Dockerfile ."
FROM debian:stretch-slim as downloader

RUN set -ex \
	&& apt-get update \
	&& apt-get install -qq --no-install-recommends ca-certificates dirmngr wget \
     qemu-user-static binfmt-support

WORKDIR /opt

RUN wget -qO /opt/tini "https://github.com/krallin/tini/releases/download/v0.18.0/tini-arm64" \
    && echo "7c5463f55393985ee22357d976758aaaecd08defb3c5294d353732018169b019 /opt/tini" | sha256sum -c - \
    && chmod +x /opt/tini

		ENV GROESTLCOIN_VERSION 2.20.1
		ENV GROESTLCOIN_TARBALL groestlcoin-${GROESTLCOIN_VERSION}-x86_64-linux-gnu.tar.gz
		ENV GROESTLCOIN_URL https://github.com/Groestlcoin/groestlcoin/releases/download/v$GROESTLCOIN_VERSION/$GROESTLCOIN_TARBALL
		ENV GROESTLCOIN_ASC_URL https://github.com/Groestlcoin/groestlcoin/releases/download/v$GROESTLCOIN_VERSION/SHA256SUMS.asc

		RUN mkdir /opt/groestlcoin && cd /opt/groestlcoin \
		    && wget -qO $GROESTLCOIN_TARBALL "$GROESTLCOIN_URL" \
		    && for server in $(shuf -e ha.pool.sks-keyservers.net \
		                             hkp://p80.pool.sks-keyservers.net:80 \
		                             keyserver.ubuntu.com \
		                             hkp://keyserver.ubuntu.com:80 \
		                             pgp.mit.edu) ; do \
		         gpg --batch --keyserver "$server" --recv-keys "$GROESTLCOIN_PGP_KEY" && break || : ; \
		       done \
		    && wget -qO groestlcoin.asc "$GROESTLCOIN_ASC_URL" \
		    && gpg --verify groestlcoin.asc \
		    && grep $GROESTLCOIN_TARBALL groestlcoin.asc | tee SHA256SUMS.asc \
		    && sha256sum -c SHA256SUMS.asc \
		    && BD=groestlcoin-$GROESTLCOIN_VERSION/bin \
		    && tar -xzvf $GROESTLCOIN_TARBALL $BD/groestlcoin-cli --strip-components=1 \
		    && rm $GROESTLCOIN_TARBALL

FROM debian:stretch-slim as builder

ENV LIGHTNINGD_VERSION=master
RUN apt-get update && apt-get install -y --no-install-recommends ca-certificates autoconf automake build-essential gettext git libtool python3 python3-mako wget gnupg dirmngr git \
  libc6-arm64-cross gcc-aarch64-linux-gnu g++-aarch64-linux-gnu

ENV target_host=aarch64-linux-gnu

ENV AR=${target_host}-ar \
AS=${target_host}-as \
CC=${target_host}-gcc \
CXX=${target_host}-g++ \
LD=${target_host}-ld \
STRIP=${target_host}-strip \
QEMU_LD_PREFIX=/usr/${target_host} \
HOST=${target_host}

RUN wget -q https://zlib.net/zlib-1.2.11.tar.gz \
&& tar xvf zlib-1.2.11.tar.gz \
&& cd zlib-1.2.11 \
&& ./configure --prefix=$QEMU_LD_PREFIX \
&& make \
&& make install && cd .. && rm zlib-1.2.11.tar.gz && rm -rf zlib-1.2.11

RUN apt-get install -y --no-install-recommends unzip tclsh \
&& wget -q https://www.sqlite.org/2019/sqlite-src-3290000.zip \
&& unzip sqlite-src-3290000.zip \
&& cd sqlite-src-3290000 \
&& ./configure --enable-static --disable-readline --disable-threadsafe --disable-load-extension --host=${target_host} --prefix=$QEMU_LD_PREFIX \
&& make \
&& make install && cd .. && rm sqlite-src-3290000.zip && rm -rf sqlite-src-3290000

RUN wget -q https://gmplib.org/download/gmp/gmp-6.1.2.tar.xz \
&& tar xvf gmp-6.1.2.tar.xz \
&& cd gmp-6.1.2 \
&& ./configure --disable-assembly --prefix=$QEMU_LD_PREFIX --host=${target_host} \
&& make \
&& make install && cd .. && rm gmp-6.1.2.tar.xz && rm -rf gmp-6.1.2
COPY --from=downloader /usr/bin/qemu-aarch64-static /usr/bin/qemu-aarch64-static
WORKDIR /opt/lightningd
COPY . /tmp/lightning
RUN git clone --recursive /tmp/lightning . && \
    git checkout $(git --work-tree=/tmp/lightning --git-dir=/tmp/lightning/.git rev-parse HEAD)

ARG DEVELOPER=0
RUN ./configure --prefix=/tmp/lightning_install --enable-static && make -j3 DEVELOPER=${DEVELOPER} && make install

FROM arm64v8/debian:stretch-slim as final
COPY --from=downloader /usr/bin/qemu-aarch64-static /usr/bin/qemu-aarch64-static
COPY --from=downloader /opt/tini /usr/bin/tini
RUN apt-get update && apt-get install -y --no-install-recommends socat inotify-tools python3 python3-pip \
    && rm -rf /var/lib/apt/lists/*

ENV LIGHTNINGD_DATA=/root/.lightning
ENV LIGHTNINGD_RPC_PORT=9835
ENV LIGHTNINGD_PORT=9735

RUN mkdir $LIGHTNINGD_DATA && \
    touch $LIGHTNINGD_DATA/config
VOLUME [ "/root/.lightning" ]
COPY --from=builder /tmp/lightning_install/ /usr/local/
COPY --from=downloader /opt/groestlcoin/bin /usr/bin
COPY tools/docker-entrypoint.sh entrypoint.sh

EXPOSE 9735 9835
ENTRYPOINT  [ "/usr/bin/tini", "-g", "--", "./entrypoint.sh" ]
