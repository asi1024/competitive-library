#pragma once

#include "../template/const_value.cpp"
#include "definition.cpp"

template <typename edge_t, typename cost_type = typename edge_t::cost_type>
std::vector<cost_type> dijkstra(const graph_t<edge_t> &g, int s) {
  std::vector<cost_type> d(g.size(), inf<cost_type>());
  d[s] = zero<cost_type>();
  using P = std::pair<cost_type, int>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> que;
  que.push(P(zero<cost_type>(), s));
  while (!que.empty()) {
    cost_type dist = que.top().first;
    int v = que.top().second;
    que.pop();
    if (d[v] < dist) continue;
    for (const auto &e : g[v]) {
      if (d[e.to] <= d[v] + e.cost) continue;
      d[e.to] = d[v] + e.cost;
      que.push(P(d[e.to], e.to));
    }
  }
  return d;
}

template <typename edge_t, typename cost_type = typename edge_t::cost_type>
std::vector<cost_type> dijkstra(const graph_t<edge_t> &g, int s,
                                std::vector<int> &prev) {
  prev.resize(g.size());
  std::vector<cost_type> d(g.size(), inf<cost_type>());
  d[s] = zero<cost_type>();
  using P = std::pair<cost_type, int>;
  std::priority_queue<P, std::vector<P>, std::greater<P>> que;
  que.push(P(zero<cost_type>(), s));
  while (!que.empty()) {
    cost_type dist = que.top().first;
    int v = que.top().second;
    que.pop();
    if (d[v] < dist) continue;
    for (const auto &e : g[v]) {
      if (d[e.to] <= d[v] + e.cost) continue;
      d[e.to] = d[v] + e.cost;
      prev[e.to] = v;
      que.push(P(d[e.to], e.to));
    }
  }
  return d;
}
