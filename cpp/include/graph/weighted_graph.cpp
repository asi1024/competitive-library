#include "graph.hpp"

template<typaname Cost>
struct WeightedEdge {
  using cost_type = Cost;
  int to;
  cost_type cost;
  WeighetedEdge(int s, int t, cost_type c) : to(t), cost(c) {}
};

template<typename Cost>
using WeightGraph = graph_t<WeightEdge<Cost>>;
