---
title: "yosupo-point_set_range_composite.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/yosupo-point_set_range_composite.cpp)

{% highlight cpp %}
#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"
#include "../include/structure/monoid.hpp"
#include "../include/structure/segment_tree.cpp"
#include "../include/types/mod.cpp"

using Mod = Modulo<998244353, true>;
using P = std::pair<Mod, Mod>;

int main() {
  int n, q, com, x, y, z;
  fcin >> n >> q;
  std::vector<P> vec;
  vec.reserve(n);
  for (int i = 0; i < n; ++i) {
    fcin >> x >> y;
    vec.emplace_back(x, y);
  }
  SegmentTree<Linear<Mod>> seg(vec);
  while (q--) {
    fcin >> com >> x >> y >> z;
    if (com == 0) {
      seg.update(x, P(y, z));
    }
    else {
      auto t = seg.query(x, y);
      fcout << int(t.first * Mod(z) + t.second) << fendl;
    }
  }
  return 0;
}
{% endhighlight %}

### Includes

- [fast_cin.cpp](../include/others/fast_cin)
- [fast_cout.cpp](../include/others/fast_cout)
- [monoid.hpp](../include/structure/monoid)
- [segment_tree.cpp](../include/structure/segment_tree)
- [mod.cpp](../include/types/mod)

[Back](..)
