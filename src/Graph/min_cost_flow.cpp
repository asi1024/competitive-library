#pragma once

#include "Graph.hpp"

template <typename Flow, typename Cost>
Cost min_cost_flow(FCGraph<Flow, Cost> &g, int s, int t, Flow f,
                   Cost inf, bool init = true) {
  const int V = g.size();
  // const Cost eps = 1e-8;
  static vector<Cost> h(V, 0), dist(V, 0);
  static vector<int> prevv(V), preve(V);
  if (init) {
    fill(begin(h), end(h), 0);
    fill(begin(dist), end(dist), 0);
    fill(begin(prevv), end(prevv), 0);
    fill(begin(preve), end(preve), 0);
  }
  using P = pair<Cost, int>;
  Cost res = 0;
  while (f > 0) {
    priority_queue<P, vector<P>, greater<P>> que;
    fill(begin(dist), end(dist), inf);
    dist[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
      P p = que.top(); que.pop();
      int v = p.second;
      if (dist[v] < p.first) continue;
      for (int i = 0; i < (int)g[v].size(); ++i) {
        const auto &e = g[v][i];
        if (e.cap <= 0) continue;
        if (dist[e.to] > dist[v] + e.cost + h[v] - h[e.to] /* + eps */) {
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          que.push(P(dist[e.to], e.to));
        }
      }
    }
    if (dist[t] == inf) return -1;
    for (int i = 0; i < V; ++i) {
      h[i] += dist[i];
    }

    Flow d = f;
    for (int v = t; v != s; v = prevv[v]) {
      d = min(d, g[prevv[v]][preve[v]].cap);
    }
    f -= d;
    res += d * h[t];
    for (int v = t; v != s; v = prevv[v]) {
      auto &e = g[prevv[v]][preve[v]];
      e.cap -= d;
      g[v][e.rev].cap += d;
    }
  }
  return res;
}

// Verified : AOJ GRL_6_B (Minimum Cost Flow)
/*
int main() {
  int V, E, F;
  cin >> V >> E >> F;
  FCGraph<int, int> g(V);
  while (E--) {
    int u, v, c, d;
    cin >> u >> v >> c >> d;
    add_edge(g, u, v, c, d);
  }
  cout << min_cost_flow(g, 0, V-1, F, int(1e9)) << endl;
  return 0;
}
*/
