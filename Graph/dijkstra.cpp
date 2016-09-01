#pragma once

#include "Graph.hpp"

template <typename Weight>
Array<Weight> dijkstra(const Graph<Weight> &g, int s) {
  const Weight INF = 1e9;
  Array<Weight> d(g.size(), INF);
  d[s] = 0;
  using P = pair<Weight,int>;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(0, s));
  while (!que.empty()) {
    Weight dist = que.top().first;
    int v = que.top().second;
    que.pop();
    if (d[v] < dist) continue;
    for (auto e: g[v]) {
      if (d[e.to] <= d[v] + e.cost) continue;
      d[e.to] = d[v] + e.cost;
      que.push(P(d[e.to], e.to));
    }
  }
  return d;
}

// Verified : AOJ GRL_1_A (Single Source Shortest Path)
/*
int main() {
  int V, E, r, s, t, d;
  cin >> V >> E >> r;
  Graph<int> g(V);
  while (E--) {
    cin >> s >> t >> d;
    add_edge(g, s, t, d);
  }
  const int INF = 1e9;
  Array<int> res = dijkstra(g, r);
  for (int i = 0; i < V; ++i) {
    if (res[i] == INF) cout << "INF" << endl;
    else cout << res[i] << endl;
  }
  return 0;
}
*/
