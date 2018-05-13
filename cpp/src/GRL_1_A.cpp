#include <cstdio>

#include "../include/graph/weighted_graph.hpp"
#include "../include/graph/dijkstra.cpp"

int main() {
  int V, E, r, s, t, d;
  scanf("%d%d%d", &V ,&E, &r);
  WeightedGraph<int> g(V);
  while (E--) {
    scanf("%d%d%d", &s ,&t, &d);
    g.add(s, t, d);
  }
  auto res = dijkstra(g, r);
  for (int i = 0; i < V; ++i) {
    if (res[i] == inf<int>) puts("INF");
    else printf("%d\n", res[i]);
  }
  return 0;
}
