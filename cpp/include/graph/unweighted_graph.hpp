#pragma once

#include "definition.hpp"

class Edge {
public:
  using cost_type = int;
  int from, to;
  static const cost_type cost = 1;
  Edge(int s, int t) : from(s), to(t) { ; }
};

using Graph = graph_t<Edge>;

void add_edge(Graph &g, int from, int to) {
  g[from].emplace_back(from, to);
  g[to].emplace_back(to, from);
}
