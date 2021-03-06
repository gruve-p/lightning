/* We can't seem to route the following:
 *
 * Expect route 03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf -> 0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae -> 02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06
 *
 * getchannels:
 * {'channels': [{'active': True, 'short_id': '6990x2x1/1', 'fee_per_kw': 10, 'delay': 5, 'message_flags': 0, 'channel_flags': 1, 'destination': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'source': '02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06', 'last_update': 1504064344}, {'active': True, 'short_id': '6989x2x1/0', 'fee_per_kw': 10, 'delay': 5, 'message_flags': 0, 'channel_flags': 0, 'destination': '03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf', 'source': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'last_update': 1504064344}, {'active': True, 'short_id': '6990x2x1/0', 'fee_per_kw': 10, 'delay': 5, 'message_flags': 0, 'channel_flags': 0, 'destination': '02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06', 'source': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'last_update': 1504064344}, {'active': True, 'short_id': '6989x2x1/1', 'fee_per_kw': 10, 'delay': 5, 'message_flags': 0, 'channel_flags': 1, 'destination': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'source': '03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf', 'last_update': 1504064344}]}
 */
#include <common/json_stream.h>
#include <common/setup.h>
#include <common/status.h>


#include <stdio.h>
#define status_fmt(level, node_id, fmt, ...)				\
	do { (void)node_id; printf((fmt) ,##__VA_ARGS__); printf("\n"); } while(0)

#include "../routing.c"
#include "../gossip_store.c"

/* AUTOGENERATED MOCKS START */
/* Generated stub for cupdate_different */
bool cupdate_different(struct gossip_store *gs UNNEEDED,
		       const struct half_chan *hc UNNEEDED,
		       const u8 *cupdate UNNEEDED)
{ fprintf(stderr, "cupdate_different called!\n"); abort(); }
/* Generated stub for fmt_wireaddr_without_port */
char *fmt_wireaddr_without_port(const tal_t *ctx UNNEEDED, const struct wireaddr *a UNNEEDED)
{ fprintf(stderr, "fmt_wireaddr_without_port called!\n"); abort(); }
/* Generated stub for fromwire_gossip_store_channel_amount */
bool fromwire_gossip_store_channel_amount(const void *p UNNEEDED, struct amount_sat *satoshis UNNEEDED)
{ fprintf(stderr, "fromwire_gossip_store_channel_amount called!\n"); abort(); }
/* Generated stub for fromwire_gossip_store_private_channel */
bool fromwire_gossip_store_private_channel(const tal_t *ctx UNNEEDED, const void *p UNNEEDED, struct amount_sat *satoshis UNNEEDED, u8 **announcement UNNEEDED)
{ fprintf(stderr, "fromwire_gossip_store_private_channel called!\n"); abort(); }
/* Generated stub for fromwire_gossip_store_private_update */
bool fromwire_gossip_store_private_update(const tal_t *ctx UNNEEDED, const void *p UNNEEDED, u8 **update UNNEEDED)
{ fprintf(stderr, "fromwire_gossip_store_private_update called!\n"); abort(); }
/* Generated stub for fromwire_gossipd_local_add_channel_obs */
bool fromwire_gossipd_local_add_channel_obs(const tal_t *ctx UNNEEDED, const void *p UNNEEDED, struct short_channel_id *short_channel_id UNNEEDED, struct node_id *remote_node_id UNNEEDED, struct amount_sat *satoshis UNNEEDED, u8 **features UNNEEDED)
{ fprintf(stderr, "fromwire_gossipd_local_add_channel_obs called!\n"); abort(); }
/* Generated stub for fromwire_wireaddr */
bool fromwire_wireaddr(const u8 **cursor UNNEEDED, size_t *max UNNEEDED, struct wireaddr *addr UNNEEDED)
{ fprintf(stderr, "fromwire_wireaddr called!\n"); abort(); }
/* Generated stub for json_add_member */
void json_add_member(struct json_stream *js UNNEEDED,
		     const char *fieldname UNNEEDED,
		     bool quote UNNEEDED,
		     const char *fmt UNNEEDED, ...)
{ fprintf(stderr, "json_add_member called!\n"); abort(); }
/* Generated stub for json_member_direct */
char *json_member_direct(struct json_stream *js UNNEEDED,
			 const char *fieldname UNNEEDED, size_t extra UNNEEDED)
{ fprintf(stderr, "json_member_direct called!\n"); abort(); }
/* Generated stub for json_object_end */
void json_object_end(struct json_stream *js UNNEEDED)
{ fprintf(stderr, "json_object_end called!\n"); abort(); }
/* Generated stub for json_object_start */
void json_object_start(struct json_stream *ks UNNEEDED, const char *fieldname UNNEEDED)
{ fprintf(stderr, "json_object_start called!\n"); abort(); }
/* Generated stub for memleak_add_helper_ */
void memleak_add_helper_(const tal_t *p UNNEEDED, void (*cb)(struct htable *memtable UNNEEDED,
						    const tal_t *)){ }
/* Generated stub for nannounce_different */
bool nannounce_different(struct gossip_store *gs UNNEEDED,
			 const struct node *node UNNEEDED,
			 const u8 *nannounce UNNEEDED)
{ fprintf(stderr, "nannounce_different called!\n"); abort(); }
/* Generated stub for notleak_ */
void *notleak_(const void *ptr UNNEEDED, bool plus_children UNNEEDED)
{ fprintf(stderr, "notleak_ called!\n"); abort(); }
/* Generated stub for peer_supplied_good_gossip */
void peer_supplied_good_gossip(struct peer *peer UNNEEDED, size_t amount UNNEEDED)
{ fprintf(stderr, "peer_supplied_good_gossip called!\n"); abort(); }
/* Generated stub for private_channel_announcement */
const u8 *private_channel_announcement(const tal_t *ctx UNNEEDED,
				       const struct short_channel_id *scid UNNEEDED,
				       const struct node_id *local_node_id UNNEEDED,
				       const struct node_id *remote_node_id UNNEEDED,
				       const u8 *features UNNEEDED)
{ fprintf(stderr, "private_channel_announcement called!\n"); abort(); }
/* Generated stub for sanitize_error */
char *sanitize_error(const tal_t *ctx UNNEEDED, const u8 *errmsg UNNEEDED,
		     struct channel_id *channel_id UNNEEDED)
{ fprintf(stderr, "sanitize_error called!\n"); abort(); }
/* Generated stub for status_failed */
void status_failed(enum status_failreason code UNNEEDED,
		   const char *fmt UNNEEDED, ...)
{ fprintf(stderr, "status_failed called!\n"); abort(); }
/* Generated stub for towire_gossip_store_channel_amount */
u8 *towire_gossip_store_channel_amount(const tal_t *ctx UNNEEDED, struct amount_sat satoshis UNNEEDED)
{ fprintf(stderr, "towire_gossip_store_channel_amount called!\n"); abort(); }
/* Generated stub for towire_gossip_store_delete_chan */
u8 *towire_gossip_store_delete_chan(const tal_t *ctx UNNEEDED, const struct short_channel_id *scid UNNEEDED)
{ fprintf(stderr, "towire_gossip_store_delete_chan called!\n"); abort(); }
/* Generated stub for towire_gossip_store_private_channel */
u8 *towire_gossip_store_private_channel(const tal_t *ctx UNNEEDED, struct amount_sat satoshis UNNEEDED, const u8 *announcement UNNEEDED)
{ fprintf(stderr, "towire_gossip_store_private_channel called!\n"); abort(); }
/* Generated stub for towire_gossip_store_private_update */
u8 *towire_gossip_store_private_update(const tal_t *ctx UNNEEDED, const u8 *update UNNEEDED)
{ fprintf(stderr, "towire_gossip_store_private_update called!\n"); abort(); }
/* Generated stub for towire_warningfmt */
u8 *towire_warningfmt(const tal_t *ctx UNNEEDED,
		      const struct channel_id *channel UNNEEDED,
		      const char *fmt UNNEEDED, ...)
{ fprintf(stderr, "towire_warningfmt called!\n"); abort(); }
/* Generated stub for update_peers_broadcast_index */
void update_peers_broadcast_index(struct list_head *peers UNNEEDED, u32 offset UNNEEDED)
{ fprintf(stderr, "update_peers_broadcast_index called!\n"); abort(); }
/* AUTOGENERATED MOCKS END */

#if DEVELOPER
/* Generated stub for memleak_remove_htable */
void memleak_remove_htable(struct htable *memtable UNNEEDED, const struct htable *ht UNNEEDED)
{ fprintf(stderr, "memleak_remove_htable called!\n"); abort(); }
/* Generated stub for memleak_remove_intmap_ */
void memleak_remove_intmap_(struct htable *memtable UNNEEDED, const struct intmap *m UNNEEDED)
{ fprintf(stderr, "memleak_remove_intmap_ called!\n"); abort(); }
#endif

/* NOOP for new_reltimer_ */
struct oneshot *new_reltimer_(struct timers *timers UNNEEDED,
			      const tal_t *ctx UNNEEDED,
			      struct timerel expire UNNEEDED,
			      void (*cb)(void *) UNNEEDED, void *arg UNNEEDED)
{
	return NULL;
}

const void *trc;

static struct half_chan *
get_or_make_connection(struct routing_state *rstate,
		       const struct node_id *from_id,
		       const struct node_id *to_id,
		       const char *shortid,
		       struct amount_sat satoshis)
{
	struct short_channel_id scid;
	struct chan *chan;
	const int idx = node_id_idx(from_id, to_id);

	if (!short_channel_id_from_str(shortid, strlen(shortid), &scid))
		abort();
	chan = get_channel(rstate, &scid);
	if (!chan)
		chan = new_chan(rstate, &scid, from_id, to_id, satoshis, NULL);

	/* Make sure it's seen as initialized (index non-zero). */
	chan->half[idx].bcast.index = 1;
	chan->half[idx].htlc_minimum = AMOUNT_MSAT(0);
	if (!amount_sat_to_msat(&chan->half[idx].htlc_maximum, satoshis))
		abort();

	return &chan->half[idx];
}

static bool channel_is_between(const struct chan *chan,
			       const struct node_id *a, const struct node_id *b)
{
	if (node_id_eq(&chan->nodes[0]->id, a)
	    && node_id_eq(&chan->nodes[1]->id, b))
		return true;

	if (node_id_eq(&chan->nodes[0]->id, b)
	    && node_id_eq(&chan->nodes[1]->id, a))
		return true;

	return false;
}

int main(int argc, char *argv[])
{
	struct half_chan *nc;
	struct routing_state *rstate;
	struct node_id a, b, c, d;
	struct amount_msat fee;
	struct chan **route;
	const double riskfactor = 1.0 / BLOCKS_PER_YEAR / 10000;

	common_setup(argv[0]);

	node_id_from_hexstr("03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf",
			   strlen("03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf"),
			   &a);
	node_id_from_hexstr("0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae",
			   strlen("0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae"),
			   &b);
	node_id_from_hexstr("02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06",
			   strlen("02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06"),
			   &c);
	node_id_from_hexstr("02cca6c5c966fcf61d121e3a70e03a1cd9eeeea024b26ea666ce974d43b242e636",
			   strlen("02cca6c5c966fcf61d121e3a70e03a1cd9eeeea024b26ea666ce974d43b242e636"),
			   &d);

	rstate = new_routing_state(tmpctx, &a, NULL, NULL, NULL, false, false);

	/* [{'active': True, 'short_id': '6990:2:1/1', 'fee_per_kw': 10, 'delay': 5, 'message_flags': 0, 'channel_flags': 1, 'destination': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'source': '02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06', 'last_update': 1504064344}, */

	nc = get_or_make_connection(rstate, &c, &b, "6990x2x1", AMOUNT_SAT(1000));
	nc->base_fee = 0;
	nc->proportional_fee = 10;
	nc->delay = 5;
	nc->channel_flags = 1;
	nc->message_flags = 0;
	nc->bcast.timestamp = 1504064344;

	/* {'active': True, 'short_id': '6989:2:1/0', 'fee_per_kw': 10, 'delay': 5, 'message_flags': 0, 'channel_flags': 0, 'destination': '03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf', 'source': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'last_update': 1504064344}, */
	nc = get_or_make_connection(rstate, &b, &a, "6989x2x1", AMOUNT_SAT(1000));
	nc->base_fee = 0;
	nc->proportional_fee = 10;
	nc->delay = 5;
	nc->channel_flags = 0;
	nc->message_flags = 0;
	nc->bcast.timestamp = 1504064344;

	/* {'active': True, 'short_id': '6990:2:1/0', 'fee_per_kw': 10, 'delay': 5, 'message_flags': 0, 'channel_flags': 0, 'destination': '02ea622d5c8d6143f15ed3ce1d501dd0d3d09d3b1c83a44d0034949f8a9ab60f06', 'source': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'last_update': 1504064344}, */
	nc = get_or_make_connection(rstate, &b, &c, "6990x2x1", AMOUNT_SAT(1000));
	nc->base_fee = 0;
	nc->proportional_fee = 10;
	nc->delay = 5;
	nc->channel_flags = 0;
	nc->message_flags = 0;
	nc->bcast.timestamp = 1504064344;
	nc->htlc_minimum = AMOUNT_MSAT(100);

	/* {'active': True, 'short_id': '6989:2:1/1', 'fee_per_kw': 10, 'delay': 5, 'message_flags': 0, 'channel_flags': 1, 'destination': '0230ad0e74ea03976b28fda587bb75bdd357a1938af4424156a18265167f5e40ae', 'source': '03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf', 'last_update': 1504064344}]} */
	nc = get_or_make_connection(rstate, &a, &b, "6989x2x1", AMOUNT_SAT(1000));
	nc->base_fee = 0;
	nc->proportional_fee = 10;
	nc->delay = 5;
	nc->channel_flags = 1;
	nc->message_flags = 0;
	nc->bcast.timestamp = 1504064344;

	route = find_route(tmpctx, rstate, &a, &c, AMOUNT_MSAT(100000), riskfactor, 0.0, NULL,
			   ROUTING_MAX_HOPS, &fee);
	assert(route);
	assert(tal_count(route) == 2);
	assert(channel_is_between(route[0], &a, &b));
	assert(channel_is_between(route[1], &b, &c));


	/* We should not be able to find a route that exceeds our own capacity */
	route = find_route(tmpctx, rstate, &a, &c, AMOUNT_MSAT(1000001), riskfactor, 0.0, NULL,
			   ROUTING_MAX_HOPS, &fee);
	assert(!route);

	/* Now test with a query that exceeds the channel capacity after adding
	 * some fees */
	route = find_route(tmpctx, rstate, &a, &c, AMOUNT_MSAT(999999), riskfactor, 0.0, NULL,
			   ROUTING_MAX_HOPS, &fee);
	assert(!route);

	/* This should fail to return a route because it is smaller than these
	 * htlc_minimum_msat on the last channel. */
	route = find_route(tmpctx, rstate, &a, &c, AMOUNT_MSAT(1), riskfactor, 0.0, NULL,
			   ROUTING_MAX_HOPS, &fee);
	assert(!route);

	/* {'active': True, 'short_id': '6990:2:1/0', 'fee_per_kw': 10, 'delay': 5, 'message_flags': 1, 'htlc_maximum_msat': 500000, 'htlc_minimum_msat': 100, 'channel_flags': 0, 'destination': '02cca6c5c966fcf61d121e3a70e03a1cd9eeeea024b26ea666ce974d43b242e636', 'source': '03c173897878996287a8100469f954dd820fcd8941daed91c327f168f3329be0bf', 'last_update': 1504064344}, */
	nc = get_or_make_connection(rstate, &a, &d, "6991x2x1", AMOUNT_SAT(1000));
	nc->base_fee = 0;
	nc->proportional_fee = 0;
	nc->delay = 5;
	nc->channel_flags = 0;
	nc->message_flags = 1;
	nc->bcast.timestamp = 1504064344;
	nc->htlc_minimum = AMOUNT_MSAT(100);
	nc->htlc_maximum = AMOUNT_MSAT(500000); /* half capacity */

	/* This should route correctly at the max_msat level */
	route = find_route(tmpctx, rstate, &a, &d, AMOUNT_MSAT(500000), riskfactor, 0.0, NULL,
			   ROUTING_MAX_HOPS, &fee);
	assert(route);

	/* This should fail to return a route because it's larger than the
	 * htlc_maximum_msat on the last channel. */
	route = find_route(tmpctx, rstate, &a, &d, AMOUNT_MSAT(500001), riskfactor, 0.0, NULL,
			   ROUTING_MAX_HOPS, &fee);
	assert(!route);

	common_shutdown();
	return 0;
}
