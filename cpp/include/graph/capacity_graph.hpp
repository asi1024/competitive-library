#pragma once

#include "definition.hpp"

template <typename Capacity> class CapacityEdge {
public:
  using capacity_type = Capacity;
  int to, rev;
  capacity_type cap;
  CapacityEdge(int, int t, capacity_type f, int r) : to(t), rev(r), cap(f) { ; }
};

template <typename Capacity> using CapacityGraph = graph_t<CapacityEdge<Capacity>>;

// template <typename Capacity>
// void add(CapacityGraph<Capacity> &g, int from, int to, Capacity cap) {
// // void CapacityGraph<Capacity>::add_(int from, int to, Capacity cap) {
//   g[from].emplace_back(from, to, cap, (int)g[to].size());
//   g[to].emplace_back(to, from, 0, (int)g[from].size() - 1);
// }

template <typename Capacity>
void add_edge(CapacityGraph<Capacity> &g, int from, int to, Capacity cap) {
  g.add(from, to, cap, (int)g[to].size());
  g.add(to, from, 0, (int)g[from].size() - 1);
}
