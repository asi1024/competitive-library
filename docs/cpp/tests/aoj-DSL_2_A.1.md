---
title: "aoj-DSL_2_A.1.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/aoj-DSL_2_A.1.cpp)

{% highlight cpp %}
#include "../include/structure/starry_sky_tree.cpp"
#include "../include/template/typedef.hpp"

int main() {
  int n, q, com, x, y;
  scanf("%d%d", &n, &q);
  StarrySkyTree<ll> seg(n);
  seg.update(0, n, INT_MAX);
  while (q--) {
    scanf("%d%d%d", &com, &x, &y);
    if (com)
      printf("%lld\n", seg.query(x, y + 1));
    else {
      int val = seg.query(x, x + 1);
      seg.update(x, x + 1, y - val);
    }
  }
  return 0;
}
{% endhighlight %}

### Includes

- [starry_sky_tree.cpp](../include/structure/starry_sky_tree)
- [typedef.hpp](../include/template/typedef)

[Back](..)
