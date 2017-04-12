## distance.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/geometry/distance.cpp)

{% highlight cpp %}
ld dist_lp(Line l, Point p) {
  return abs(p - proj(l, p));
}

ld dist_ll(Line l, Line m) {
  return isis_ll(l, m) ? 0 : dist_lp(l, m.a);
}

ld dist_ls(Line l, Segment s) {
  if (isis_ls(l, s)) return 0;
  return min(dist_lp(l, s.a), dist_lp(l, s.b));
}

ld dist_sp(Segment s, Point p) {
  Point r = proj(Line(s), p);
  if (isis_sp(s, r)) return abs(r - p);
  return min(abs(s.a - p), abs(s.b - p));
}

ld dist_ss(Segment s, Segment t) {
  if (isis_ss(s, t)) return 0;
  ld a = min(dist_sp(s, t.a), dist_sp(t, s.a));
  ld b = min(dist_sp(s, t.b), dist_sp(t, s.b));
  return min(a, b);
}
{% endhighlight %}

- [Back](../../../..)
