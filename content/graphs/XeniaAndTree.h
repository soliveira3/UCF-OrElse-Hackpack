/**
 * Author: Samuel Oliveira
 * Date: 2025-10-08
 * Description: Solution for Fixed-Length-Paths using centroid decomp
 * The number of fixed-length-paths that go through each node / total number of paths
 * Usage:
 * ancestors.assign(n, vector<pair<int, int>>());
 * adj.assign(n, vector<int>());
 * subSize.assign(n, 1);
 * removed.assign(n, false);
 * ans.assign(n, 1e8);
 * decomp(0);
 * For each centroid, find it's distance to all other nodes.
 * Each update should update the closest for each centroid to the special node to min(cur, distNewSpecialNode)
 * Each query should return min((distNode to centroid) + minDistSpecialNodeFromCentroid) for each parant centroid
 */

// in fixed length paths    
int getSize(int u, int p)
int findCentroid(int u, int p, int n) {} 

void getDist(ll u, ll p, ll c, ll d)
{
    for (int v : adj[u])
        if (v != p && !removed[v])
            getDist(v, u, c, d+1);
 
    ancestors[u].push_back({c, d});
}

int buildDecomp(int node)
{
    int centroid = findCentroid(node, -1, getSize(node, -1));

    for (int v : adj[centroid])
        if (!removed[v])
            getDist(v, centroid, centroid, 1);
 
    ancestors[centroid].push_back({centroid, 0});
    removed[centroid] = true;
 
    for (int v : adj[centroid])
        if (!removed[v]) buildDecomp(v);
 
    return centroid;
}
