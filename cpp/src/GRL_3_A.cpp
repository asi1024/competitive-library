#include "../include/graph/articulation_points.cpp"
#include "../include/graph/bidirected_graph.hpp"

using namespace std;

int main() {
  int V, E, s, t;
  scanf("%d%d", &V, &E);
  BidirectedGraph g(V);
  while (E--) {
    scanf("%d%d", &s, &t);
    add_edge(g, s, t);
  }
  set<int> art = articulation_points(g).first;
  for (int i : art) printf("%d\n", i);
  return 0;
}
