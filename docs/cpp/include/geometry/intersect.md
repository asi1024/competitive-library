## isis_ll

{% highlight cpp %}
bool isis_ll(Line l, Line m);{% endhighlight %}

## isis_ls

{% highlight cpp %}
bool isis_ls(Line l, Segment s);{% endhighlight %}

## isis_lp

{% highlight cpp %}
bool isis_lp(Line l, Point p);{% endhighlight %}

## isis_ss

{% highlight cpp %}
bool isis_ss(Segment s, Segment t);{% endhighlight %}

## isis_sp

{% highlight cpp %}
bool isis_sp(Segment s, Point p);{% endhighlight %}

## proj

{% highlight cpp %}
Point proj(Line l, Point p);{% endhighlight %}

## mirror

{% highlight cpp %}
Point mirror(Line l, Point p);{% endhighlight %}

## is_ll

{% highlight cpp %}
Point is_ll(Line s, Line t);{% endhighlight %}### Includes

- [Geometry.hpp](Geometry)

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/geometry/intersect.cpp)

{% highlight cpp %}
#include "Geometry.hpp"

bool isis_ll(Line l, Line m) {
  return abs(cross(l.b - l.a, m.b - m.a)) > eps;
}

bool isis_ls(Line l, Segment s) {
  ld a = cross(l.b - l.a, s.a - l.a);
  ld b = cross(l.b - l.a, s.b - l.a);
  return (a * b < eps);
}

bool isis_lp(Line l, Point p) {
  return abs(cross(l.b - p, l.a - p)) < eps;
}

bool isis_ss(Segment s, Segment t) {
  return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
    ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

bool isis_sp(Segment s, Point p) {
  return abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < eps;
}

Point proj(Line l, Point p) {
  ld t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + t * (l.a - l.b);
}

Point mirror(Line l, Point p) {
  return (ld)2 * proj(l, p) - p;
}

Point is_ll(Line s, Line t) {
  Point sv = s.b - s.a, tv = t.b - t.a;
  return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
}
{% endhighlight %}

[Back](../..)
