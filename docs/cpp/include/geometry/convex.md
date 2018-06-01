{% include mathjax.html %}

## convex_hull

{% highlight cpp %}
Polygon<real_t> convex_hull(std::vector< Point< real_t >> ps);
{% endhighlight %}

## max_distance

{% highlight cpp %}
real_t max_distance(const std::vector< Point< real_t >> &ps);
{% endhighlight %}

## convex_cut

{% highlight cpp %}
Polygon<real_t> convex_cut(const Polygon< real_t > &g, const Line< real_t > &l);
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/geometry/convex.cpp)

{% highlight cpp %}
#include "polygon.cpp"

template <typename real_t>
Polygon<real_t> convex_hull(std::vector<Point<real_t>> ps) {
  int n = ps.size(), k = 0;
  sort(begin(ps), end(ps));
  Polygon<real_t> res(2 * n);
  for (int i = 0; i < n; res[k++] = ps[i++])
    while (k >= 2 && ccw(res[k - 2], res[k - 1], ps[i]) <= 0) --k;
  for (int i = n - 2, t = k + 1; i >= 0; res[k++] = ps[i--])
    while (k >= t && ccw(res[k - 2], res[k - 1], ps[i]) <= 0) --k;
  res.resize(k - 1);
  return res;
}

template <typename real_t>
real_t max_distance(const std::vector<Point<real_t>> &ps) {
  assert(ps.size() > 1);
  Polygon<real_t> g = convex_hull(ps);
  int a = 0, b = 1;
  real_t res = abs(g[0] - g[1]);
  while (a < (int)g.size()) {
    if (arg((g[a + 1] - g[a]) * std::conj(g[b] - g[b + 1])) > 0)
      ++b;
    else
      ++a;
    res = std::max(res, abs(g[a] - g[b]));
  }
  return res;
}

template <typename real_t>
Polygon<real_t> convex_cut(const Polygon<real_t> &g, const Line<real_t> &l) {
  const int n = g.size();
  Polygon<real_t> res;
  for (int i = 0; i < n; i++) {
    Point<real_t> p = g[i], q = g[i + 1];
    if (ccw(l.a, l.b, p) != -1) res.push_back(p);
    if (ccw(l.a, l.b, p) * ccw(l.a, l.b, q) < 0) {
      res.push_back(is_ll(Line<real_t>(p, q), l));
    }
  }
  return res;
}
{% endhighlight %}

### Includes

- [polygon.cpp](polygon)

[Back](../..)
