---
title: "yosupo-vertex_set_path_composite.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/yosupo-vertex_set_path_composite.cpp)

{% highlight cpp %}
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
{% endhighlight %}

### Includes

- [bidirected_graph.cpp](../include/graph/bidirected_graph)
- [fast_cin.cpp](../include/others/fast_cin)
- [fast_cout.cpp](../include/others/fast_cout)
- [euler_tour.cpp](../include/structure/euler_tour)
- [monoid.cpp](../include/structure/monoid)
- [mod.cpp](../include/types/mod)

[Back](..)
