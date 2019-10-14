---
title: "DSL_1_A.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/DSL_1_A.cpp)

{% highlight cpp %}
#include <cstdio>

#include "../include/structure/unionfind.cpp"

int main() {
  int n, q, com, x, y;
  scanf("%d%d", &n, &q);
  UnionFind uf(n);
  while (q--) {
    scanf("%d%d%d", &com, &x, &y);
    if (com)
      printf("%d\n", uf.same(x, y));
    else
      uf.unite(x, y);
  }
  return 0;
}
{% endhighlight %}

### Includes

- [unionfind.cpp](../include/structure/unionfind)

[Back](..)
