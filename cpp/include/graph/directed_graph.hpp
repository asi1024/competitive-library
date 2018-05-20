#pragma once

#include "definition.hpp"

class DirectedEdge {
public:
  using cost_type = int;
  int to;
  static const cost_type cost = 1;
  DirectedEdge(int, int t) : to(t) { ; }
};

using DirectedGraph = graph_t<DirectedEdge>;

void add_edge(DirectedGraph &g, int from, int to) {
  g[from].emplace_back(from, to);
}
