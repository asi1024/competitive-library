#include "../util.hpp"
#include "../../src/Graph/spfa.cpp"

double test_spfa() {
  auto g = random_cgraph(-100, 1000);
  Timer timer;
  spfa(g, 0, (int)1e9);
  return timer.stop() / edge_num;
}
