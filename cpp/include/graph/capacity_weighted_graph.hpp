#pragma once

#include "definition.hpp"

template <typename Capacity, typename Cost> class CapacityWeightedEdge {
public:
  using capacity_type = Capacity;
  using cost_type = Cost;
  int to, rev;
  capacity_type cap;
  cost_type cost;
  CapacityWeightedEdge(int, int t, int r, capacity_type f, cost_type c)
      : to(t), rev(r), cap(f), cost(c) {
    ;
  }
};

template <typename Capacity, typename Cost>
using CapacityWeightedGraph = graph_t<CapacityWeightedEdge<Capacity, Cost>>;
