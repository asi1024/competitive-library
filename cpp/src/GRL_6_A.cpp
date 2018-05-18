#include "../include/graph/max_flow.cpp"
#include "../include/graph/capacity_graph.hpp"

using namespace std;

int main() {
  int V, E, u, v, c;
  scanf("%d%d", &V, &E);
  CapacityGraph<int> g(V);
  while (E--) {
    scanf("%d%d%d", &u, &v, &c);
    add_edge(g, u, v, c);
  }
  printf("%d\n", max_flow(g, 0, V - 1));
  return 0;
}
