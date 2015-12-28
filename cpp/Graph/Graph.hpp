#pragma once

#include "../util.hpp"

template <typename Weight>
struct Edge{
  int from, to; Weight cost;
  Edge(int s, int t, Weight c) : from(s), to(t), cost(c) {}
};

template<typename Weight> using Edges = vector<Edge<Weight>>;
template<typename Weight> using Graph = vector<Edges<Weight>>;
template<typename Weight> using Array = vector<Weight>;

template<typename Weight>
void add_edge(Graph<Weight> &g, int from, int to, Weight cost) {
  g[from].push_back(Edge<Weight>(from, to, cost));
}
