#include "Graph.hpp"

/*
template <typename Weight>
void add_edge(Graph<Weight> &g, int src, int to) {
  g[src].push_back(Edge<Weight>(src, to));
  g[to].push_back(Edge<Weight>(to, src));
}
*/

class LCA {
  int V, LOG_V;
  vector<vector<int>> parent;
  vector<int> depth;
  template<typename T>
  void dfs(const Graph<T> &g, int v, int p, int d) {
    parent[0][v] = p; depth[v] = d;
    for (const Edge<T> &e: g[v])
      if (e.to != p) dfs(g, e.to, v, d + 1);
  }
public:
  template<typename T>
  LCA(const Graph<T> &g, int root) : V(g.size()), LOG_V(0), depth(V, 0) {
    for (int v = V; v > 0; v >>= 1) ++LOG_V;
    parent.assign(LOG_V, vector<int>(V, 0));
    dfs(g, root, -1, 0);
    for (int k = 0; k < LOG_V - 1; ++k) {
      for (int v = 0; v < V; ++v) {
        if (parent[k][v] < 0) parent[k + 1][v] = -1;
        else parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
  int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < LOG_V; ++k)
      if (((depth[v] - depth[u]) >> k) & 1) v = parent[k][v];
    if (u == v) return u;
    for (int k = LOG_V - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};
