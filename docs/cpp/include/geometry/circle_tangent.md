{% include mathjax.html %}

## tangent_cp

{% highlight cpp %}
std::vector<Line<real_t> > tangent_cp(const Circle< real_t > &c, const Point< real_t > &p);
{% endhighlight %}

## tangent_cc

{% highlight cpp %}
std::vector<Line<real_t> > tangent_cc(const Circle< real_t > &c1, const Circle< real_t > &c2);
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/geometry/circle_tangent.cpp)

{% highlight cpp %}
#include "Geometry.hpp"

template <typename real_t>
std::vector<Line<real_t>> tangent_cp(const Circle<real_t> &c,
                                     const Point<real_t> &p) {
  std::vector<Line<real_t>> res;
  Vector<real_t> v = c.p - p;
  real_t d = abs(v), len = sqrt(norm(v) - c.r * c.r);
  if (isnan(len)) {
    return res;
  }
  const auto v1 = v * Vector<real_t>(len / d, c.r / d);
  const auto v2 = v * Vector<real_t>(len / d, -c.r / d);
  res.emplace_back(p, p + v1);
  if (len <= 0) return res;
  res.emplace_back(p, p + v2);
  return res;
}

template <typename real_t>
std::vector<Line<real_t>> tangent_cc(const Circle<real_t> &c1,
                                     const Circle<real_t> &c2) {
  std::vector<Line<real_t>> res;
  if (abs(c1.p - c2.p) - (c1.r + c2.r) >= 0) {
    Point<real_t> center = average(c1.p, c2.p, c2.r, c1.r);
    res = tangent_cp(c1, center);
  }
  if (c1.r - c2.r != 0) {
    const Point<real_t> out = average(c1.p, c2.p, -c2.r, c1.r);
    const std::vector<Line<real_t>> nres = tangent_cp(c1, out);
    res.insert(res.end(), begin(nres), end(nres));
  }
  else {
    Vector<real_t> v = c2.p - c1.p;
    v /= abs(v);
    Point<real_t> q1 = c1.p + v * Vector<real_t>(0, 1) * c1.r;
    Point<real_t> q2 = c1.p + v * Vector<real_t>(0, -1) * c1.r;
    res.emplace_back(q1, q1 + v);
    res.emplace_back(q2, q2 + v);
  }
  return res;
}
{% endhighlight %}

### Includes

- [Geometry.hpp](Geometry)

[Back](../..)
