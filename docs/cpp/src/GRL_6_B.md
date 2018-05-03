### Includes

- [min_cost_flow.cpp](../include/graph/min_cost_flow)

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/GRL_6_B.cpp)

{% highlight cpp %}
#include "../include/graph/min_cost_flow.cpp"

int main() {
  int V, E, F;
  scanf("%d%d%d", &V, &E, &F);
  Graph g(V);
  while (E--) {
    int u, v, c, d;
    scanf("%d%d%d%d", &u, &v, &c, &d);
    add_edge(g, u, v, c, d);
  }
  printf("%d\n", min_cost_flow(g, 0, V-1, F));
  return 0;
}
{% endhighlight %}

[Back](..)
