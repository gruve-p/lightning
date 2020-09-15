#include "../common/base32.c"
#include "../common/wireaddr.c"

#include <stdio.h>
#include <assert.h>
#include <ccan/mem/mem.h>
#include <common/amount.h>

/* AUTOGENERATED MOCKS START */
/* Generated stub for amount_asset_is_main */
bool amount_asset_is_main(struct amount_asset *asset UNNEEDED)
{ fprintf(stderr, "amount_asset_is_main called!\n"); abort(); }
/* Generated stub for amount_asset_to_sat */
struct amount_sat amount_asset_to_sat(struct amount_asset *asset UNNEEDED)
{ fprintf(stderr, "amount_asset_to_sat called!\n"); abort(); }
/* Generated stub for amount_sat */
struct amount_sat amount_sat(u64 satoshis UNNEEDED)
{ fprintf(stderr, "amount_sat called!\n"); abort(); }
/* Generated stub for amount_sat_add */
 bool amount_sat_add(struct amount_sat *val UNNEEDED,
				       struct amount_sat a UNNEEDED,
				       struct amount_sat b UNNEEDED)
{ fprintf(stderr, "amount_sat_add called!\n"); abort(); }
/* Generated stub for amount_sat_eq */
bool amount_sat_eq(struct amount_sat a UNNEEDED, struct amount_sat b UNNEEDED)
{ fprintf(stderr, "amount_sat_eq called!\n"); abort(); }
/* Generated stub for amount_sat_greater_eq */
bool amount_sat_greater_eq(struct amount_sat a UNNEEDED, struct amount_sat b UNNEEDED)
{ fprintf(stderr, "amount_sat_greater_eq called!\n"); abort(); }
/* Generated stub for amount_sat_sub */
 bool amount_sat_sub(struct amount_sat *val UNNEEDED,
				       struct amount_sat a UNNEEDED,
				       struct amount_sat b UNNEEDED)
{ fprintf(stderr, "amount_sat_sub called!\n"); abort(); }
/* Generated stub for amount_sat_to_asset */
struct amount_asset amount_sat_to_asset(struct amount_sat *sat UNNEEDED, const u8 *asset UNNEEDED)
{ fprintf(stderr, "amount_sat_to_asset called!\n"); abort(); }
/* Generated stub for amount_tx_fee */
struct amount_sat amount_tx_fee(u32 fee_per_kw UNNEEDED, size_t weight UNNEEDED)
{ fprintf(stderr, "amount_tx_fee called!\n"); abort(); }
/* Generated stub for fromwire */
const u8 *fromwire(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, void *copy UNNEEDED, size_t n UNNEEDED)
{ fprintf(stderr, "fromwire called!\n"); abort(); }
/* Generated stub for fromwire_amount_sat */
struct amount_sat fromwire_amount_sat(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_amount_sat called!\n"); abort(); }
/* Generated stub for fromwire_bool */
bool fromwire_bool(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_bool called!\n"); abort(); }
/* Generated stub for fromwire_fail */
void *fromwire_fail(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_fail called!\n"); abort(); }
/* Generated stub for fromwire_secp256k1_ecdsa_signature */
void fromwire_secp256k1_ecdsa_signature(const u8 **cursor UNNEEDED, size_t *max UNNEEDED,
					secp256k1_ecdsa_signature *signature UNNEEDED)
{ fprintf(stderr, "fromwire_secp256k1_ecdsa_signature called!\n"); abort(); }
/* Generated stub for fromwire_sha256 */
void fromwire_sha256(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, struct sha256 *sha256 UNNEEDED)
{ fprintf(stderr, "fromwire_sha256 called!\n"); abort(); }
/* Generated stub for fromwire_tal_arrn */
u8 *fromwire_tal_arrn(const tal_t *ctx UNNEEDED,
		       const u8 **cursor UNNEEDED, size_t *max UNNEEDED, size_t num UNNEEDED)
{ fprintf(stderr, "fromwire_tal_arrn called!\n"); abort(); }
/* Generated stub for fromwire_u16 */
u16 fromwire_u16(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u16 called!\n"); abort(); }
/* Generated stub for fromwire_u32 */
u32 fromwire_u32(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u32 called!\n"); abort(); }
/* Generated stub for fromwire_u64 */
u64 fromwire_u64(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u64 called!\n"); abort(); }
/* Generated stub for fromwire_u8 */
u8 fromwire_u8(const u8 **cursor UNNEEDED, size_t *max UNNEEDED)
{ fprintf(stderr, "fromwire_u8 called!\n"); abort(); }
/* Generated stub for fromwire_u8_array */
void fromwire_u8_array(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, u8 *arr UNNEEDED, size_t num UNNEEDED)
{ fprintf(stderr, "fromwire_u8_array called!\n"); abort(); }
/* Generated stub for towire */
void towire(u8 **pptr UNNEEDED, const void *data UNNEEDED, size_t len UNNEEDED)
{ fprintf(stderr, "towire called!\n"); abort(); }
/* Generated stub for towire_amount_sat */
void towire_amount_sat(u8 **pptr UNNEEDED, const struct amount_sat sat UNNEEDED)
{ fprintf(stderr, "towire_amount_sat called!\n"); abort(); }
/* Generated stub for towire_bool */
void towire_bool(u8 **pptr UNNEEDED, bool v UNNEEDED)
{ fprintf(stderr, "towire_bool called!\n"); abort(); }
/* Generated stub for towire_secp256k1_ecdsa_signature */
void towire_secp256k1_ecdsa_signature(u8 **pptr UNNEEDED,
			      const secp256k1_ecdsa_signature *signature UNNEEDED)
{ fprintf(stderr, "towire_secp256k1_ecdsa_signature called!\n"); abort(); }
/* Generated stub for towire_sha256 */
void towire_sha256(u8 **pptr UNNEEDED, const struct sha256 *sha256 UNNEEDED)
{ fprintf(stderr, "towire_sha256 called!\n"); abort(); }
/* Generated stub for towire_u16 */
void towire_u16(u8 **pptr UNNEEDED, u16 v UNNEEDED)
{ fprintf(stderr, "towire_u16 called!\n"); abort(); }
/* Generated stub for towire_u32 */
void towire_u32(u8 **pptr UNNEEDED, u32 v UNNEEDED)
{ fprintf(stderr, "towire_u32 called!\n"); abort(); }
/* Generated stub for towire_u64 */
void towire_u64(u8 **pptr UNNEEDED, u64 v UNNEEDED)
{ fprintf(stderr, "towire_u64 called!\n"); abort(); }
/* Generated stub for towire_u8 */
void towire_u8(u8 **pptr UNNEEDED, u8 v UNNEEDED)
{ fprintf(stderr, "towire_u8 called!\n"); abort(); }
/* Generated stub for towire_u8_array */
void towire_u8_array(u8 **pptr UNNEEDED, const u8 *arr UNNEEDED, size_t num UNNEEDED)
{ fprintf(stderr, "towire_u8_array called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */

int main(void)
{
	setup_locale();

	struct wireaddr addr;
	char *ip;
	u16 port;

	setup_tmpctx();

	/* Grossly invalid. */
	assert(!separate_address_and_port(tmpctx, "[", &ip, &port));
	assert(!separate_address_and_port(tmpctx, "[123", &ip, &port));
	assert(!separate_address_and_port(tmpctx, "[::1]:8f", &ip, &port));
	assert(!separate_address_and_port(tmpctx, "127.0.0.1:8f", &ip, &port));
	assert(!separate_address_and_port(tmpctx, "127.0.0.1:0", &ip, &port));
	assert(!separate_address_and_port(tmpctx, "127.0.0.1:ff", &ip, &port));

	/* ret = getaddrinfo("[::1]:80", NULL, NULL, &res); */
	assert(separate_address_and_port(tmpctx, "[::1]:80", &ip, &port));
	assert(streq(ip, "::1"));
	assert(port == 80);

	port = 0;
	assert(separate_address_and_port(tmpctx, "ip6-localhost", &ip, &port));
	assert(streq(ip, "ip6-localhost"));
	assert(port == 0);

	assert(separate_address_and_port(tmpctx, "::1", &ip, &port));
	assert(streq(ip, "::1"));
	assert(port == 0);

	assert(separate_address_and_port(tmpctx, "192.168.1.1:8000", &ip, &port));
	assert(streq(ip, "192.168.1.1"));
	assert(port == 8000);

	port = 0;
	assert(separate_address_and_port(tmpctx, "192.168.2.255", &ip, &port));
	assert(streq(ip, "192.168.2.255"));
	assert(port == 0);

	// unusual but possibly valid case
	assert(separate_address_and_port(tmpctx, "[::1]", &ip, &port));
	assert(streq(ip, "::1"));
	assert(port == 0);

	// service names not supported yet
	assert(!separate_address_and_port(tmpctx, "[::1]:http", &ip, &port));

	// localhost hostnames for backward compat
	assert(parse_wireaddr("localhost", &addr, 200, false, NULL));
	assert(addr.port == 200);

	// string should win the port battle
	assert(parse_wireaddr("[::1]:9735", &addr, 500, false, NULL));
	assert(addr.port == 9735);
	ip = fmt_wireaddr(tmpctx, &addr);
	assert(streq(ip, "[::1]:9735"));

	// should use argument if we have no port in string
	assert(parse_wireaddr("2001:db8:85a3::8a2e:370:7334", &addr, 9777, false, NULL));
	assert(addr.port == 9777);

	ip = fmt_wireaddr(tmpctx, &addr);
	assert(streq(ip, "[2001:db8:85a3::8a2e:370:7334]:9777"));

	assert(parse_wireaddr("[::ffff:127.0.0.1]:49150", &addr, 1, false, NULL));
	assert(addr.port == 49150);

	assert(parse_wireaddr("4ruvswpqec5i2gogopxl4vm5bruzknbvbylov2awbo4rxiq4cimdldad.onion:49150", &addr, 1, false, NULL));
	assert(addr.port == 49150);

	assert(parse_wireaddr("4ruvswpqec5i2gogopxl4vm5bruzknbvbylov2awbo4rxiq4cimdldad.onion", &addr, 1, false, NULL));
	assert(addr.port == 1);

	assert(parse_wireaddr("odpzvneidqdf5hdq.onion:49150", &addr, 1, false, NULL));
	assert(addr.port == 49150);

	assert(parse_wireaddr("odpzvneidqdf5hdq.onion", &addr, 1, false, NULL));
	assert(addr.port == 1);

	assert(tal_count(wireaddr_from_hostname(tmpctx, "odpzvneidqdf5hdq.onion", 1, NULL, NULL, NULL)) > 0);
	assert(wireaddr_from_hostname(tmpctx, "aaa.onion", 1, NULL, NULL, NULL) == NULL);

	tal_free(tmpctx);
	return 0;
}
