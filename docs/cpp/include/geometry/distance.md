---
title: "distance.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/geometry/distance.cpp)

{% highlight cpp %}
#include "intersect.cpp"

template <typename real_t>
real_t dist_lp(const Line<real_t> &l, const Point<real_t> &p) {
  return abs(p - proj(l, p));
}

template <typename real_t>
real_t dist_ll(const Line<real_t> &l, const Line<real_t> &m) {
  return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

template <typename real_t>
real_t dist_ls(const Line<real_t> &l, const Segment<real_t> &s) {
  if (isis_ls(l, s)) return 0;
  return std::min(dist_lp(l, s.a), dist_lp(l, s.b));
}

template <typename real_t>
real_t dist_sp(const Segment<real_t> &s, const Point<real_t> &p) {
  Point<real_t> r = proj(Line<real_t>(s), p);
  if (isis_sp(s, r)) return abs(r - p);
  return std::min(abs(s.a - p), abs(s.b - p));
}

template <typename real_t>
real_t dist_ss(const Segment<real_t> &s, const Segment<real_t> &t) {
  if (isis_ss(s, t)) return 0;
  real_t a = std::min(dist_sp(s, t.a), dist_sp(t, s.a));
  real_t b = std::min(dist_sp(s, t.b), dist_sp(t, s.b));
  return std::min(a, b);
}
{% endhighlight %}

### Includes

- [intersect.cpp](intersect)

[Back](../..)
