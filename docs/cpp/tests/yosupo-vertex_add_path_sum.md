---
title: "yosupo-vertex_add_path_sum.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/yosupo-vertex_add_path_sum.cpp)

{% highlight cpp %}
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
{% endhighlight %}

### Includes

- [bidirected_graph.cpp](../include/graph/bidirected_graph)
- [fast_cin.cpp](../include/others/fast_cin)
- [fast_cout.cpp](../include/others/fast_cout)
- [euler_tour.cpp](../include/structure/euler_tour)
- [monoid.cpp](../include/structure/monoid)

[Back](..)
