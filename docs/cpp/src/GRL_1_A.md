{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/GRL_1_A.cpp)

{% highlight cpp %}
#include <cstdio>

#include "../include/graph/dijkstra.cpp"
#include "../include/graph/weighted_graph.hpp"

int main() {
  int V, E, r, s, t, d;
  scanf("%d%d%d", &V, &E, &r);
  WeightedGraph<int> g(V);
  while (E--) {
    scanf("%d%d%d", &s, &t, &d);
    add_edge(g, s, t, d);
  }
  auto res = dijkstra(g, r);
  for (int i = 0; i < V; ++i) {
    if (res[i] == inf<int>())
      puts("INF");
    else
      printf("%d\n", res[i]);
  }
  return 0;
}
{% endhighlight %}

### Includes

- [dijkstra.cpp](../include/graph/dijkstra)
- [weighted_graph.hpp](../include/graph/weighted_graph)

[Back](..)
