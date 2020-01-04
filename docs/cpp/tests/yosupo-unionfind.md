---
title: "yosupo-unionfind.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/yosupo-unionfind.cpp)

{% highlight cpp %}
#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"
#include "../include/structure/unionfind.cpp"

int main() {
  int n, q, com, u, v;
  fcin >> n >> q;
  UnionFind uf(n);
  while (q--) {
    fcin >> com >> u >> v;
    if (com) {
      fcout << int(uf.same(u, v)) << fendl;
    }
    else {
      uf.unite(u, v);
    }
  }
  return 0;
}
{% endhighlight %}

### Includes

- [fast_cin.cpp](../include/others/fast_cin)
- [fast_cout.cpp](../include/others/fast_cout)
- [unionfind.cpp](../include/structure/unionfind)

[Back](..)
