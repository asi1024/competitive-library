#pragma once

#include "Graph.hpp"

class LCA {
  int size, log_size;
  vector<vector<int>> parent;
  vector<int> depth;
  void dfs(const Graph &g, int v, int p, int d) {
    parent[0][v] = p; depth[v] = d;
    for (const Edge &e: g[v]) {
      if (e.to != p) dfs(g, e.to, v, d + 1);
    }
  }
public:
  LCA(const Graph &g, int root) : size(g.size()), log_size(0), depth(size, 0) {
    for (int v = size; v > 0; v /= 2) ++log_size;
    parent.assign(log_size, vector<int>(size, 0));
    dfs(g, root, -1, 0);
    for (int k = 0; k < log_size - 1; ++k) {
      for (int v = 0; v < size; ++v) {
        if (parent[k][v] < 0) parent[k + 1][v] = -1;
        else parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
  int query(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int k = 0; k < log_size; ++k)
      if (((depth[v] - depth[u]) >> k) & 1) v = parent[k][v];
    if (u == v) return u;
    for (int k = log_size - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};

// Verified : AOJ GRL_5_C (Lowest Common Ancestor)
/*
int main() {
  int n, q;
  cin >> n;
  Graph g(n);
  for (int i = 0; i < n; ++i) {
    int k, c;
    cin >> k;
    while (k--) {
      cin >> c;
      add_edge(g, i, c);
    }
  }
  LCA lca(g, 0);
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << lca.query(u, v) << endl;
  }
  return 0;
}
*/
