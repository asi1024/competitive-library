{% include mathjax.html %}

## tangent_cp

{% highlight cpp %}
vector<Line> tangent_cp(Circle c, Point p);
{% endhighlight %}

## tangent_cc

{% highlight cpp %}
vector<Line> tangent_cc(Circle c1, Circle c2);
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/geometry/circle_tangent.cpp)

{% highlight cpp %}
#include "Geometry.hpp"

vector<Line> tangent_cp(Circle c, Point p) {
  vector<Line> res;
  Point v = c.p - p;
  ld d = abs(v), len = sqrt(norm(v) - c.r * c.r);
  if (isnan(len)) {
    return res;
  }
  Point v1 = v * Point(len / d, c.r / d);
  Point v2 = v * Point(len / d, -c.r / d);
  res.push_back(Line(p, p + v1));
  if (len < eps)
    return res;
  res.push_back(Line(p, p + v2));
  return res;
}

vector<Line> tangent_cc(Circle c1, Circle c2) {
  vector<Line> res;
  if (abs(c1.p - c2.p) - (c1.r + c2.r) > -eps) {
    Point center = (c1.p * c2.r + c2.p * c1.r) / (c1.r + c2.r);
    res = tangent_cp(c1, center);
  }
  if (abs(c1.r - c2.r) > eps) {
    Point out = (-c1.p * c2.r + c2.p * c1.r) / (c1.r - c2.r);
    vector<Line> nres = tangent_cp(c1, out);
    res.insert(res.end(), begin(nres), end(nres));
  } else {
    Point v = c2.p - c1.p;
    v /= abs(v);
    Point q1 = c1.p + v * Point(0, 1) * c1.r;
    Point q2 = c1.p + v * Point(0, -1) * c1.r;
    res.push_back(Line(q1, q1 + v));
    res.push_back(Line(q2, q2 + v));
  }
  return res;
}
{% endhighlight %}

### Includes

- [Geometry.hpp](Geometry)

[Back](../..)
