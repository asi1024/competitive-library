---
title: "aoj-GRL_6_A.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/aoj-GRL_6_A.cpp)

{% highlight cpp %}
#include "../include/graph/capacity_graph.cpp"
#include "../include/graph/max_flow.cpp"

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
{% endhighlight %}

### Includes

- [capacity_graph.cpp](../include/graph/capacity_graph)
- [max_flow.cpp](../include/graph/max_flow)

[Back](..)
