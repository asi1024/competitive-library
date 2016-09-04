#include "../util.hpp"
#include "../../src/Graph/dijkstra.cpp"

double test_dijkstra() {
  auto g = random_cgraph(0, 1000);
  Timer timer;
  dijkstra(g, 0, (int)1e9);
  return timer.stop() / edge_num;
}
