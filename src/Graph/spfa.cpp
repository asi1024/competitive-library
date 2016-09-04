#pragma once

#include "Graph.hpp"

template <typename Cost>
pair<bool,vector<Cost>> spfa(const CGraph<Cost> &g, int s, Cost inf, Cost zero = 0) {
  const int n = g.size();
  vector<Cost> d(n, inf); d[s] = zero;
  vector<int> updated(n, 0);
  vector<bool> inque(n, false);
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int from = que.front();
    que.pop();
    inque[from] = false;
    ++updated[from];
    if (updated[from] == n+1) return {false, d}; // negative cycle
    for (auto e: g[from]) {
      Cost cost = d[from] + e.cost;
      if (cost < d[e.to]) {
        d[e.to] = cost;
        if (!inque[e.to]) {
          que.push(e.to);
          inque[e.to] = true;
        }
      }
    }
  }
  return {true, d};
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
  const int INF = 1e9;
  auto res = spfa(g, r, INF).second;
  for (int i = 0; i < V; ++i) {
    if (res[i] == INF) cout << "INF" << endl;
    else cout << res[i] << endl;
  }
  return 0;
}
*/

// Verified : AOJ GRL_1_B (Single Source Shortest Path (Negative Edges))
/*
int main() {
  int V, E, r, s, t, d;
  cin >> V >> E >> r;
  CGraph<int> g(V);
  while (E--) {
    cin >> s >> t >> d;
    add_edge(g, s, t, d);
  }
  const int INF = 1e9;
  bool flag;
  vector<int> res;
  tie(flag, res) = spfa(g, r, INF);
  if (flag) {
    for (int i = 0; i < V; ++i) {
      if (res[i] == INF) cout << "INF" << endl;
      else cout << res[i] << endl;
    }
  }
  else {
    cout << "NEGATIVE CYCLE" << endl;
  }
  return 0;
}
*/
