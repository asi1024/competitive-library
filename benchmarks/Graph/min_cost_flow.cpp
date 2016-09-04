#include "../util.hpp"
#include "../../src/Graph/min_cost_flow.cpp"

double test_min_cost_flow() {
  auto g = random_fcgraph(5000, 10000, 50, 50);
  Timer timer;
  min_cost_flow(g, 0, 1, 50, int(1e9));
  return timer.stop() / 5e5;
}
