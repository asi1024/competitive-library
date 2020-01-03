---
title: "aoj-GRL_1_B.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/aoj-GRL_1_B.cpp)

{% highlight cpp %}
#include <cstdio>
#include <tuple>

#include "../include/graph/spfa.cpp"
#include "../include/graph/weighted_graph.hpp"

using namespace std;

int main() {
  int V, E, r, s, t, d;
  scanf("%d%d%d", &V, &E, &r);
  WeightedGraph<int> g(V);
  while (E--) {
    scanf("%d%d%d", &s, &t, &d);
    add_edge(g, s, t, d);
  }
  vector<int> res = spfa(g, r);
  if (!res.empty()) {
    for (int i = 0; i < V; ++i) {
      if (res[i] == inf<int>())
        puts("INF");
      else
        printf("%d\n", res[i]);
    }
  }
  else {
    puts("NEGATIVE CYCLE");
  }
  return 0;
}
{% endhighlight %}

### Includes

- [spfa.cpp](../include/graph/spfa)
- [weighted_graph.hpp](../include/graph/weighted_graph)

[Back](..)
