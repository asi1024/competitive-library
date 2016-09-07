#pragma once

#include "Graph.hpp"

template <typename Cost>
vector<Cost> bfs01(const CGraph<Cost> &g, int s, Cost zero = 0) {
  vector<Cost> d(g.size(), inf<Cost>());
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
