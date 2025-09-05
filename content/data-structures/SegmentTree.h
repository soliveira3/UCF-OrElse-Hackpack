/**
 * Author: Samuel Oliveira
 * Date: 2025-08-17
 * Description: General Segment Tree with functionality for common problems.
 * Usage: set(i, v, 0, 0, SIZE)
 */

typedef struct Tree
{
    ll size;
    vll vals;
    ll NEUTRAL_ELEMENT = 0;
    ll f(ll a, ll b) { return a + b; }

    void init(ll n) {
        size = 1;
        while (size < n) size *= 2;
        vals.assign(2 * size, 0LL);
    }

    void build(vll &a, ll x, ll lx, ll rx) {
        if (lx + 1 == rx) {
            if (lx < (ll)a.size()) vals[x] = a[lx];
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        vals[x] = f(vals[2 * x + 1], vals[2 * x + 2]);
    }

    void set(ll i, ll v, ll x, ll lx, ll rx) {
        if (lx + 1 == rx) {
            vals[x] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if (i < m) set(i, v, 2 * x + 1, lx, m);
        else set(i, v, 2 * x + 2, m, rx);
        vals[x] = f(vals[2 * x + 1], vals[2 * x + 2]);
    }

    ll calc(ll l, ll r, ll x, ll lx, ll rx) {
        if (lx >= r || l >= rx) return NEUTRAL_ELEMENT;
        if (lx >= l && rx <= r) return vals[x];
        ll m = (lx + rx) / 2;
        ll s1 = calc(l, r, 2 * x + 1, lx, m);
        ll s2 = calc(l, r, 2 * x + 2, m, rx);
        return f(s1, s2);
    }

    ll findKth(ll k, ll x, ll lx, ll rx) {
        if (lx + 1 == rx) return lx;
        ll m = (lx + rx) / 2;
        ll sl = vals[2*x + 1];
        if (k < sl) return findKth(k, 2*x + 1, lx, m);
        else return findKth(k-sl, 2*x + 2, m, rx);
    }

    ll first_above(ll v, ll l, ll x, ll lx, ll rx) {
        if (vals[x] < v) return -1;
        if (rx <= l) return -1;
        if (rx - lx == 1) return lx;
        ll m = (lx + rx) / 2;
        ll res = first_above(v, l, 2*x + 1, lx, m);
        if (res == -1) res = first_above(v, l, 2*x + 2, m, rx);
        return res;
    }


} Tree;
