#include "../util.hpp"

double test_spfa() {
  auto g = random_cgraph(0, 1000);
  Timer timer;
  spfa(g, 0, (int)1e9);
  return timer.stop() / edge_num;
}
