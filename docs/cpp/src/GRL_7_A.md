---
title: "GRL_7_A.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/GRL_7_A.cpp)

{% highlight cpp %}
#include "../include/graph/bipartite_matching.cpp"

int main() {
  int X, Y, E, x, y;
  scanf("%d%d%d", &X, &Y, &E);
  BipartiteMatching mat(X, Y);
  while (E--) {
    scanf("%d%d", &x, &y);
    mat.add(x, y);
  }
  printf("%d\n", mat.maximum_matching());
  return 0;
}
{% endhighlight %}

### Includes

- [bipartite_matching.cpp](../include/graph/bipartite_matching)

[Back](..)
