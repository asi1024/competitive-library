---
title: "unionfind.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/unionfind.cpp)

{% highlight cpp %}
#include "../template/includes.cpp"

class UnionFind {
  std::vector<int> p;

public:
  UnionFind(int n) : p(n, -1) {}

  int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }

  bool same(int x, int y) { return root(x) == root(y); }

  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (p[y] < p[x]) std::swap(x, y);
    if (p[x] == p[y]) --p[x];
    p[y] = x;
    return true;
  }
};
{% endhighlight %}

### Includes

- [includes.cpp](../template/includes)

[Back](../..)
