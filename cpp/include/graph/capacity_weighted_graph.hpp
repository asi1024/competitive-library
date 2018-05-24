#pragma once

#include "definition.hpp"

template <typename Capacity, typename Cost> class CapacityWeightedEdge {
public:
  using capacity_type = Capacity;
  using cost_type = Cost;
  int to, rev;
  capacity_type cap;
  cost_type cost;
  CapacityWeightedEdge(int, int t, int r, capacity_type f, cost_type c) :
    to(t), rev(r), cap(f), cost(c) {
    ;
  }
};

template <typename Capacity, typename Cost>
using CapacityWeightedGraph = graph_t<CapacityWeightedEdge<Capacity, Cost>>;

template <typename Capacity, typename Cost>
void add_edge(CapacityWeightedGraph<Capacity, Cost> &g, int from, int to,
              Capacity cap, Cost cost) {
  g[from].emplace_back(from, to, (int)g[to].size(), cap, cost);
  g[to].emplace_back(to, from, (int)g[from].size() - 1, zero<Capacity>(),
                     -cost);
}
