#include "../include/graph/bidirected_graph.cpp"
#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"
#include "../include/structure/euler_tour.cpp"
#include "../include/structure/monoid.cpp"

using Graph = BidirectedGraph;

int main() {
  int n, q, u, v, op;
  fcin >> n >> q;
  std::vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    fcin >> a[i];
  }
  Graph g(n);
  for (int i = 0; i < n - 1; ++i) {
    fcin >> u >> v;
    add_edge(g, u, v);
  }
  LCA lca(g, 0);
  EulerTour<RSQ<long long>> et(g, 0);
  for (int i = 0; i < n; ++i) {
    et.update(i, a[i]);
  }
  while (q--) {
    fcin >> op >> u >> v;
    if (op == 0) {
      a[u] += v;
      et.update(u, a[u]);
    }
    else {
      fcout << et.query(lca, u, v) << fendl;
    }
  }
  return 0;
}
