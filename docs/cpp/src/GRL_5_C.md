### Includes

- [lca.cpp](../include/graph/lca)

{% highlight cpp %}
#include "../include/graph/lca.cpp"

int main() {
  int n, q;
  scanf("%d", &n);
  Graph g(n);
  for (int i = 0; i < n; ++i) {
    int k, c;
    scanf("%d", &k);
    while (k--) {
      scanf("%d", &c);
      add_edge(g, i, c);
    }
  }
  LCA lca(g, 0);
  scanf("%d", &q);
  while (q--) {
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", lca.query(u, v));
  }
  return 0;
}
{% endhighlight %}

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/GRL_5_C.cpp)

[Back](..)
