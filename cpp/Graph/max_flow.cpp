#pragma once

#include "Graph.hpp"

template <typename Weight>
Flow augment(Graph<Weight> &g, vector<Flow> &d, vector<int> &iter,
         int v, int t, Flow f) {
  if (v == t) return f;
  for (int &i = iter[v]; i < (int)g[v].size(); i++) {
    auto &e = g[v][i];
    if (e.cap > 0 && d[v] < d[e.to]) {
      Flow ff = augment(g, d, iter, e.to, t, min(f, e.cap));
      if (ff > 0) {
        e.cap -= ff;
        g[e.to][e.rev].cap += ff;
        return ff;
      }
    }
  }
  return 0;
}

template <typename Weight>
Flow max_flow(Graph<Weight> &g, int s, int t) {
  const int V = g.size();
  const Flow INF = 1e9;
  Flow flow = 0;
  for (;;) {
    vector<Flow> d(V, -1);
    queue<int> que;
    d[s] = 0;
    que.push(s);
    while(!que.empty()) {
      int v = que.front(); que.pop();
      for (auto e: g[v]) {
        if (e.cap <= 0 || d[e.to] >= 0) continue;
        d[e.to] = d[v] + 1;
        que.push(e.to);
      }
    }
    if (d[t] < 0) return flow;
    vector<int> iter(V, 0);
    Flow f;
    while ((f = augment(g, d, iter, s, t, INF)) > 0) flow += f;
  }
}

// Verified : AOJ GRL_6_A (Maximum Flow)
/*
int main() {
  int V, E, u, v, c;
  cin >> V >> E;
  Graph<int> g(V);
  while (E--) {
    cin >> u >> v >> c;
    add_edge(g, u, v, c);
  }
  cout << max_flow(g, 0, V-1) << endl;
  return 0;
}
*/
