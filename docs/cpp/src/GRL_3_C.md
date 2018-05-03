

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/GRL_3_C.cpp)

{% highlight cpp %}
#include "../include/graph/scc.cpp"

int main() {
  int V, E, Q, s, t, u, v;
  scanf("%d%d", &V, &E);
  Graph g(V);
  while (E--) {
    scanf("%d%d", &s, &t);
    add_edge(g, s, t);
  }
  scanf("%d", &Q);
  vector<int> cmp = scc(g);
  while (Q--) {
    scanf("%d%d", &u, &v);
    printf("%d\n", int(cmp[u] == cmp[v]));
  }
  return 0;
}
{% endhighlight %}

### Includes

- [scc.cpp](../include/graph/scc)

[Back](..)
