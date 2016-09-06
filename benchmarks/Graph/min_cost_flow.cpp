#include "../util.hpp"

double test_min_cost_flow() {
  auto g = random_fcgraph(2000, 10000, 50, 50);
  Timer timer;
  min_cost_flow(g, 0, 1, 50);
  return timer.stop() / 5e5;
}
