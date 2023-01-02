#include "../include/graph/bidirected_graph.cpp"
#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"
#include "../include/structure/euler_tour.cpp"
#include "../include/structure/monoid.cpp"
#include "../include/types/mod.cpp"

using Graph = BidirectedGraph;

int main() {
  int n, q, u, v;
  fcin >> n >> q;
  Graph g(n);
  for (int i = 1; i < n; ++i) {
    fcin >> u;
    add_edge(g, u, i);
  }
  LCA lca(g, 0);
  while (q--) {
    fcin >> u >> v;
    fcout << lca.query(u, v) << fendl;
  }
  return 0;
}
