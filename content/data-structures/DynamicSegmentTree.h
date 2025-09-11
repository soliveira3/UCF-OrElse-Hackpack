/**
 * Author: CP-Algo
 * Description: Segment Tree that only create nodes for used values.
 * Consider using offline value compression before using a DST
 */

struct Node {
    ll lo, hi;
    ll val = 0;
    Node *left = nullptr, *right = nullptr;
    Node(ll lo, ll hi) : lo(lo), hi(hi) {}
    void extend() {
        if (!left && lo + 1 < hi) {
            ll t = (lo + hi) / 2;
            left = new Node(lo, t);
            right = new Node(t, hi);
        }
    }
    void add(ll k, ll x) {
        extend();
        val += x;
        if (left) {
            if (k < left->hi) left->add(k, x);
            else right->add(k, x);
        }
    }
    ll get_sum(ll lq, ll rq) {
        if (lq <= lo && hi <= rq) return val;
        if (max(lo, lq) >= min(hi, rq)) return 0;
        extend();
        return left->get_sum(lq, rq) + right->get_sum(lq, rq);
    }
};