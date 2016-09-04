#include "../util.hpp"
#include "../../src/Graph/bfs01.cpp"

double test_bfs01() {
  auto g = random_cgraph(0, 2);
  Timer timer;
  bfs01(g, 0, (int)1e9);
  return timer.stop() / edge_num;
}
