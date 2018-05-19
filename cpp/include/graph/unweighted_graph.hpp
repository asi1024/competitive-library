#pragma once

#include "definition.hpp"

class Edge {
public:
  using cost_type = int;
  int to;
  cost_type cost = 1;
  Edge(int, int t) : to(t) { ; }
};

using Graph = graph_t<Edge>;
