#pragma once

#include "definition.hpp"

class Edge {
public:
  using cost_type = int;
  int from, to;
  cost_type cost = 1;
  Edge(int s, int t) : from(s), to(t) { ; }
};

using Graph = graph_t<Edge>;
