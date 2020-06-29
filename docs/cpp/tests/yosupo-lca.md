---
title: "yosupo-lca.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/yosupo-lca.cpp)

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
{% endhighlight %}

### Includes

- [bidirected_graph.cpp](../include/graph/bidirected_graph)
- [fast_cin.cpp](../include/others/fast_cin)
- [fast_cout.cpp](../include/others/fast_cout)
- [euler_tour.cpp](../include/structure/euler_tour)
- [monoid.cpp](../include/structure/monoid)
- [mod.cpp](../include/types/mod)

[Back](..)
