

### Includes

- [spfa.cpp](../include/graph/spfa)

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/GRL_1_B.cpp)

{% highlight cpp %}
#include "../include/graph/spfa.cpp"

int main() {
  int V, E, r, s, t, d;
  scanf("%d%d%d", &V, &E, &r);
  Graph g(V);
  while (E--) {
    scanf("%d%d%d", &s, &t, &d);
    add_edge(g, s, t, d);
  }
  bool flag;
  vector<int> res;
  tie(flag, res) = spfa(g, r);
  if (flag) {
    for (int i = 0; i < V; ++i) {
      if (res[i] == inf<int>) puts("INF");
      else printf("%d\n", res[i]);
    }
  }
  else {
    puts("NEGATIVE CYCLE");
  }
  return 0;
}
{% endhighlight %}

[Back](..)
