---
title: "aoj-DSL_2_G.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/aoj-DSL_2_G.cpp)

{% highlight cpp %}
#include "../include/structure/rars.cpp"
#include "../include/template/typedef.cpp"

int main() {
  int n, q, com, s, t, x;
  scanf("%d%d", &n, &q);
  RARS<ll> bit(n + 1);
  while (q--) {
    scanf("%d%d%d", &com, &s, &t);
    if (com)
      printf("%lld\n", bit.query(s, t + 1));
    else {
      scanf("%d", &x);
      bit.update(s, t + 1, x);
    }
  }
  return 0;
}
{% endhighlight %}

### Includes

- [rars.cpp](../include/structure/rars)
- [typedef.cpp](../include/template/typedef)

[Back](..)
