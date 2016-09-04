#include "../util.hpp"
#include "../../src/Graph/max_flow.cpp"

double test_max_flow() {
  int V = 10000, E = 20000;
  auto g = random_fgraph(10000, 20000, 1000);
  Timer timer;
  max_flow(g, 0, 1, (int)1e9);
  return timer.stop() / E / V / V;
}
