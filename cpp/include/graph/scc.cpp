#pragma once

#include "../util.hpp"

struct Edge {
  int to;
  Edge(int t) : to(t) {}
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph &g, int from, int to) {
  g[from].emplace_back(to);
}

vector<int> scc(const Graph &graph) {
  const int n = graph.size();
  vector<vector<int>> g(n), rg(n);
  vector<int> cmp(n), vs;
  vector<bool> used(n, false);
  for (int i = 0; i < n; ++i) {
    for (Edge e: graph[i]) {
      g[i].push_back(e.to);
      rg[e.to].push_back(i);
    }
  }
  function<void(int)> dfs = [&g, &vs, &used, &dfs](int v) {
    used[v] = true;
    for (int i: g[v]) if (!used[i]) dfs(i);
    vs.push_back(v);
  };
  function<void(int,int)> rdfs = [&rg, &cmp, &used, &rdfs](int v, int k) {
    used[v] = true; cmp[v] = k;
    for (int i: rg[v]) if (!used[i]) rdfs(i, k);
  };
  for (int v = 0; v < n; ++v) {
    if (!used[v]) dfs(v);
  }
  used = vector<bool>(n, false);
  reverse(begin(vs), end(vs));
  int k = 0;
  for(int i: vs) if (!used[i]) rdfs(i, k++);
  return cmp;
}
