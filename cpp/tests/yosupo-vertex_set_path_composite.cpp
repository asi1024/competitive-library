#include "../include/graph/bidirected_graph.cpp"
#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"
#include "../include/structure/euler_tour.cpp"
#include "../include/structure/monoid.cpp"
#include "../include/types/mod.cpp"

using Mod = Modulo<998244353, true>;
using Graph = BidirectedGraph;

int main() {
  int n, q, u, v, x, op;
  fcin >> n >> q;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    fcin >> a[i] >> b[i];
  }
  Graph g(n);
  for (int i = 0; i < n - 1; ++i) {
    fcin >> u >> v;
    add_edge(g, u, v);
  }
  LCA lca(g, 0);
  EulerTour<Linear<Mod>> et(g, 0);
  for (int i = 0; i < n; ++i) {
    et.update(i, { a[i], b[i] });
  }
  while (q--) {
    fcin >> op >> u >> v >> x;
    if (op == 0) {
      et.update(u, { v, x });
    }
    else {
      auto linear = et.query(lca, u, v);
      int res = int(linear.first * Mod(x) + linear.second);
      fcout << res << fendl;
    }
  }
  return 0;
}
