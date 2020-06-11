---
title: "yosupo-range_affine_range_sum.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/yosupo-range_affine_range_sum.cpp)

{% highlight cpp %}
#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"
#include "../include/structure/monoid.cpp"
#include "../include/structure/segment_tree_lazy.cpp"
#include "../include/types/mod.cpp"

using Mod = Modulo<998244353, true>;

struct RangeSum {
  using value_type = std::pair<Mod, Mod>;
  static value_type id() { return value_type(0, 0); }
  static value_type op(const value_type &l, const value_type &r) {
    return value_type(l.first + r.first, l.second + r.second);
  }
};

// TODO: Change interface later.
template <typename T> struct MyLinear {
  using value_type = std::pair<T, T>;
  static value_type id() { return value_type(1, 0); }
  static value_type op(const value_type &l, const value_type &r) {
    return value_type(l.first * r.first, r.second * l.first + l.second);
  }
};

struct RangeAffineRangeSum {
  using Monoid = RangeSum;
  using Update = MyLinear<Mod>;
  using value_type = typename Monoid::value_type;
  using update_type = typename Update::value_type;
  static value_type evaluate(const update_type &update, const value_type &x) {
    return { update.first * x.first + update.second * x.second, x.second };
  }
};

int main() {
  int N, Q, op, a, b, c, l, r;
  fcin >> N >> Q;
  std::vector<std::pair<Mod, Mod>> array;
  array.reserve(N);
  for (int i = 0; i < N; ++i) {
    fcin >> a;
    array.emplace_back(a, 1);
  }
  SegmentTreeLazy<RangeAffineRangeSum> seg(array);
  while (Q--) {
    fcin >> op >> l >> r;
    if (op == 0) {
      fcin >> b >> c;
      seg.update(l, r, std::pair<Mod, Mod>(b, c));
    }
    else {
      fcout << int(seg.query(l, r).first) << fendl;
    }
  }
  return 0;
}
{% endhighlight %}

### Includes

- [fast_cin.cpp](../include/others/fast_cin)
- [fast_cout.cpp](../include/others/fast_cout)
- [monoid.cpp](../include/structure/monoid)
- [segment_tree_lazy.cpp](../include/structure/segment_tree_lazy)
- [mod.cpp](../include/types/mod)

[Back](..)
