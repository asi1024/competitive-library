#pragma once

#include "Graph.hpp"

template <typename Weight>
Array<Weight> bfs01(const Graph<Weight> &g, int s) {
  const Weight INF = 1e9;
  Array<Weight> d(g.size(), INF);
  d[s] = 0;
  typedef pair<Weight,int> P;
  deque<P> que;
  que.push_back(P(0, s));
  while (!que.empty()) {
    P top = que.front(); que.pop_front();
    Weight dist = top.first; int v = top.second;
    if (d[v] < dist) continue;
    for (auto e: g[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        if (e.cost) que.push_back(P(d[e.to], e.to));
        else que.push_front(P(d[e.to], e.to));
      }
    }
  }
  return d;
}
