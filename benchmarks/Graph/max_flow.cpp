#include "../util.hpp"

double test_max_flow() {
  auto g = random_fgraph(vertex_num, edge_num, 1000);
  Timer timer;
  max_flow(g, 0, 1, (int)1e9);
  return timer.stop() / edge_num;
}
