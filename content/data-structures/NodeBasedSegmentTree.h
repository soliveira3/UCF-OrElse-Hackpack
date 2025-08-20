/**
 * Author: Samuel Oliveira
 * Description: Simple node based segment tree for quick typing on more unique problems
 */

struct node
{
    pll val = {LLONG_MAX, LLONG_MAX};
    ll lo, hi, mid;
    node *left = nullptr, *right = nullptr;
 
    node (ll l, ll h) : lo(l), hi(h)
    {
        mid = (lo + hi) / 2;
        if (lo + 1 == hi) return;
        left = new node(lo, mid);
        right = new node(mid, hi);
    }
 
    void merge()
    {
        val = min(left->val, right->val);
    }
 
    void set(ll i, ll x)
    {
        if (lo + 1 == hi)
        {
            val = {x, i};
            return;
        }
 
        if (i < mid) left->set(i, x);
        else right->set(i, x);
        merge();
    }
 
    pll query(ll l, ll r)
    {
        if (r <= lo || l >= hi) return { LLONG_MAX, LLONG_MAX };
        if (lo >= l && hi <= r) return val;
        return min(left->query(l, r), right->query(l, r));
    }
};
