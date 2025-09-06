
/**
 * Author: Samuel Oliveira
 * Description: Small to Large merging for a tree.
 * Find the number of distinct colors in each node's subtree
 * Usage:
 * a.assign(n, 0);
 * nodeSize.assign(n, 1);
 * distinct.assign(n, 0);
 * colors.assign(n, set<ll>());
 * adj.assign(n, vll());
 * dfs(0, -1);
 */

void dfs(ll u, ll p)
{
    ll big = -1;
    for (ll v : adj[u])
    {
        if (v == p) continue;
        dfs(v, u);
        if (big == -1 || nodeSize[v] > nodeSize[big]) big = v;
        nodeSize[u] += nodeSize[v];
    }

    if (big != -1) swap(colors[u], colors[big]);

    for (ll v : adj[u])
        if (v != big && v != p)
            colors[u].insert(all(colors[v]));

    colors[u].insert(a[u]);
    distinct[u] = sz(colors[u]);
}

