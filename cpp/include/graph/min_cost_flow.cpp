#pragma once

#include "../util.hpp"

template <typename Flow, typename Cost>
struct Edge {
  int from, to;
  Flow cap; int rev;
  Cost cost;
  Edge(int s, int t, Flow f, int r, Cost c) :
    from(s), to(t), cap(f), rev(r), cost(c) {}
};

template<typename Flow, typename Cost>
using Graph = vector<vector<Edge<Flow, Cost>>>;

template <typename Flow, typename Cost>
void add_edge(Graph<Flow, Cost> &g, int from, int to, Flow cap, Cost cost) {
  g[from].emplace_back(from, to, cap, (int)g[to].size(), cost);
  g[to].emplace_back(to, from, 0, (int)g[from].size() - 1, -cost);
}

template <typename Flow, typename Cost>
Cost min_cost_flow(Graph<Flow, Cost> &g, int s, int t, Flow f,
                   bool init = true) {
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
    fill(begin(dist), end(dist), inf<Cost>);
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
    if (dist[t] == inf<Cost>) return -1;
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
