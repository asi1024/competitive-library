#pragma once

#include "definition.hpp"

template <typename Cost> class WeightedEdge {
public:
  using cost_type = Cost;
  int to;
  cost_type cost;
  WeightedEdge(int, int t, cost_type c) : to(t), cost(c) { ; }
};

template <typename Cost> using WeightedGraph = graph_t<WeightedEdge<Cost>>;

template <typename Cost>
void add_edge(WeightedGraph<Cost> &g, int from, int to, Cost cost) {
  g[from].emplace_back(from, to, cost);
}
