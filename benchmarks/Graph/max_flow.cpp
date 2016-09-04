#include "../util.hpp"
#include "../../src/Graph/max_flow.cpp"

double test_max_flow() {
  auto g = random_fgraph(100000, 200000, 1000);
  Timer timer;
  max_flow(g, 0, 1, (int)1e9);
  return timer.stop() / 2e5;
}
