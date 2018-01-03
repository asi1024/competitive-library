## circle_intersect.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/geometry/circle_intersect.cpp)

### Includes

- [Geometry.hpp](Geometry)
- [intersect.cpp](intersect)
- [distance.cpp](distance)

{% highlight cpp %}
#include "Geometry.hpp"
#include "intersect.cpp"
#include "distance.cpp"

vector<Point> is_cc(Circle c1, Circle c2){
  vector<Point> res;
  ld d = abs(c1.p - c2.p);
  ld rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
  ld dfr = c1.r * c1.r - rc * rc;
  if (abs(dfr) < eps) dfr = 0.0;
  else if (dfr < 0.0) return res; // no intersection
  ld rs = sqrt(dfr);
  Point diff = (c2.p - c1.p) / d;
  res.push_back(c1.p + diff * Point(rc, rs));
  if (dfr != 0.0) res.push_back(c1.p + diff * Point(rc, -rs));
  return res;
}

vector<Point> is_cl(Circle c, Line l){
  vector<Point> res;
  ld d = dist_lp(l, c.p);
  if (d < c.r + eps){
    ld len = (d > c.r) ? 0.0 : sqrt(c.r * c.r - d * d); //safety;
    Point nor = (l.a - l.b) / abs(l.a - l.b);
    res.push_back(proj(l, c.p) + len * nor);
    if (len != 0.0) res.push_back(proj(l, c.p) - len * nor);
  }
  return res;
}

vector<Point> is_cs(Circle c, Segment s){
  vector<Point> v = is_cl(c, Line(s)), res;
  for (Point p : v)
    if (isis_sp(s, p)) res.push_back(p);
  return res;
}
{% endhighlight %}

[Back](../..)
