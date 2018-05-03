## convex_hull

{% highlight cpp %}
Polygon convex_hull(vector< Point > ps);{% endhighlight %}

## max_distance

{% highlight cpp %}
ld max_distance(const vector< Point > &ps);{% endhighlight %}

## convex_cut

{% highlight cpp %}
Polygon convex_cut(const Polygon &g, Line l);{% endhighlight %}### Includes

- [intersect.cpp](intersect)

{% highlight cpp %}
#include "intersect.cpp"

Polygon convex_hull(vector<Point> ps) {
  int n = ps.size(), k = 0;
  sort(begin(ps), end(ps), comp);
  Polygon res(2 * n);
  for (int i = 0; i < n; res[k++] = ps[i++])
    while (k >= 2 && ccw(res[k - 2], res[k - 1], ps[i]) <= 0) --k;
  for (int i = n - 2, t = k + 1; i >= 0; res[k++] = ps[i--])
    while (k >= t && ccw(res[k - 2], res[k - 1], ps[i]) <= 0) --k;
  res.resize(k - 1);
  return res;
}

ld max_distance(const vector<Point> &ps) {
  assert (ps.size() > 1);
  Polygon g = convex_hull(ps);
  int a = 0, b = 1;
  ld res = abs(g[0] - g[1]);
  while (a < (int)g.size()) {
    if (arg((at(g,a+1)-at(g,a)) / (at(g,b)-at(g,b+1))) > 0) ++b; else ++a;
    res = max(res, abs(at(g,a) - at(g,b)));
  }
  return res;
}

Polygon convex_cut(const Polygon &g, Line l) {
  const int n = g.size();
  Polygon res;
  for (int i = 0; i < n; i++) {
    Point p = at(g, i), q = at(g, i + 1);
    if (ccw(l.a, l.b, p) != -1) res.push_back(p);
    if (ccw(l.a, l.b, p) * ccw(l.a, l.b, q) < 0) {
      res.push_back(is_ll(Line(p, q), l));
    }
  }
  return res;
}
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/geometry/convex.cpp)

[Back](../..)
