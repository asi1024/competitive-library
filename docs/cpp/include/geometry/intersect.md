---
title: "intersect.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/geometry/intersect.cpp)

{% highlight cpp %}
#include "Geometry.hpp"

template <typename real_t> struct Segment {
  Point<real_t> a, b;
  Segment(const Point<real_t> &p, const Point<real_t> &q) : a(p), b(q) { ; }
};

template <typename real_t> struct Line {
  Point<real_t> a, b;
  Line(const Point<real_t> &p, const Point<real_t> &q) : a(p), b(q) { ; }
  explicit Line(const Segment<real_t> &s) : a(s.a), b(s.b) { ; }
};

template <typename real_t>
bool isis_ll(const Line<real_t> &l, const Line<real_t> &m) {
  return cross(l.b - l.a, m.b - m.a) != 0;
}

template <typename real_t>
bool isis_lp(const Line<real_t> &l, const Point<real_t> &p) {
  return cross(l.b - p, l.a - p) == 0;
}

template <typename real_t>
bool isis_ls(const Line<real_t> &l, const Segment<real_t> &s) {
  return isis_lp(l, s.a) && isis_lp(l, s.b);
}

template <typename real_t>
bool isis_ss(const Segment<real_t> &s, const Segment<real_t> &t) {
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
         ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

template <typename real_t>
bool isis_sp(const Segment<real_t> &s, const Point<real_t> &p) {
  return abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) <= 0;
}

template <typename real_t>
Point<real_t> proj(const Line<real_t> &l, const Point<real_t> &p) {
  real_t t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + t * (l.a - l.b);
}

template <typename real_t>
Point<real_t> mirror(const Line<real_t> &l, const Point<real_t> &p) {
  Point<real_t> h = proj(l, p);
  return average(h, p, 2, -1);
}

template <typename real_t>
Point<real_t> is_ll(const Line<real_t> &s, const Line<real_t> &t) {
  Vector<real_t> sv = s.b - s.a, tv = t.b - t.a;
  return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}
{% endhighlight %}

### Includes

- [Geometry.hpp](Geometry)

[Back](../..)
