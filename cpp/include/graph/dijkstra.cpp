#pragma once

#include "../util.hpp"

template <typename Edge>
vector<typename Edge::Cost> dijkstra(const vector<vector<Edge>> &g, int s,
                                     typename Edge::Cost zero = 0) {
  using Cost = typename Edge::Cost;
  vector<Cost> d(g.size(), inf<Cost>);
  d[s] = zero;
  using P = pair<Cost,int>;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(zero, s));
  while (!que.empty()) {
    Cost dist = que.top().first;
    int v = que.top().second;
    que.pop();
    if (d[v] < dist) continue;
    for (const auto &e: g[v]) {
      if (d[e.to] <= d[v] + e.cost) continue;
      d[e.to] = d[v] + e.cost;
      que.push(P(d[e.to], e.to));
    }
  }
  return d;
}

struct Edge {
  using Cost = int;
  int to;
  Cost cost;
  Edge(int t, Cost c) : to(t), cost(c) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to, Edge::Cost cost) {
  g[from].emplace_back(to, cost);
}
