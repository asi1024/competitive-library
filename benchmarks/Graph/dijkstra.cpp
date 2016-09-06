#include "../util.hpp"

double test_dijkstra() {
  auto g = random_cgraph(0, 1000);
  Timer timer;
  dijkstra(g, 0);
  return timer.stop() / edge_num;
}
