#pragma once

#include "../util.hpp"

template <typename Cost>
struct Edge {
  int from, to;
  Cost cost;
  Edge(int s, int t, Cost c) : from(s), to(t), cost(c) {}
};

template<typename Cost> using Graph = vector<vector<Edge<Cost>>>;

template <typename Cost>
void add_edge(Graph<Cost> &g, int from, int to, Cost cost) {
  g[from].emplace_back(from, to, cost);
}

template <typename Cost>
vector<Cost> bfs01(const Graph<Cost> &g, int s, Cost zero = 0) {
  vector<Cost> d(g.size(), inf<Cost>);
  d[s] = zero;
  using P = pair<Cost,int>;
  deque<P> que;
  que.push_back(P(zero, s));
  while (!que.empty()) {
    P top = que.front(); que.pop_front();
    Cost dist = top.first; int v = top.second;
    if (d[v] < dist) continue;
    for (const auto &e: g[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        if (e.cost) que.push_back(P(d[e.to], e.to));
        else que.push_front(P(d[e.to], e.to));
      }
    }
  }
  return d;
}
