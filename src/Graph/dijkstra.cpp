#pragma once

#include "Graph.hpp"

template <typename Cost>
vector<Cost> dijkstra(const CGraph<Cost> &g, int s, Cost zero = 0) {
  vector<Cost> d(g.size(), inf<Cost>());
  d[s] = zero;
  using P = pair<Cost,int>;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(zero, s));
  while (!que.empty()) {
    Cost dist = que.top().first;
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
  CGraph<int> g(V);
  while (E--) {
    cin >> s >> t >> d;
    add_edge(g, s, t, d);
  }
  auto res = dijkstra(g, r);
  for (int i = 0; i < V; ++i) {
    if (res[i] == inf<int>()) cout << "INF" << endl;
    else cout << res[i] << endl;
  }
  return 0;
}
*/
