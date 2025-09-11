/**
 * Author: Samuel Oliveira
 * Date: 2025-10-08
 * Description: Solution for Fixed-Length-Paths using centroid decomp
 * The number of fixed-length-paths that go through each node / total number of paths
 * Usage:
 * map<ll, ll> sizes, curSizes; 
 * adj.assign(n, vector<int>());
 * subSize.assign(n, 1);
 * removed.assign(n, false);
 * decomp(0);
 */

int getSize(int u, int p)
{
    subSize[u] = 1;
    for (int v : adj[u])
        if (v != p && !removed[v])
            subSize[u] += getSize(v, u);
    return subSize[u];
}
int findCentroid(int u, int p, int n)
{
    for (int v : adj[u])
        if (v != p && !removed[v] && subSize[v] > n / 2)
            return findCentroid(v, u, n);
    return u;
}
void go(int u, int p, int d)
{
    if (d > k) return;
    ans += sizes[k - d];
    curSizes[d]++;
    for (int v : adj[u])
        if (v != p && !removed[v])
            go(v, u, d + 1);
}
void decomp(int node)
{
    int n = getSize(node, -1);
    if (n < k) return;
    int centroid = findCentroid(node, -1, n);
    removed[centroid] = true;
    sizes.clear();
    sizes[0] = 1;
    for (int v : adj[centroid])
        if (!removed[v]) {
            curSizes.clear();
            go(v, centroid, 1);
            for (auto pr : curSizes) sizes[pr.first] += pr.second;
        }
    if (ans == 0) return;
    for (int v : adj[centroid])
        if (!removed[v]) decomp(v);
}