## convex.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/geometry/convex.cpp)

{% highlight cpp %}
ld area(const Polygon &g) {
  ld res = 0;
  int n = g.size();
  for (int i = 0; i < n; ++i)
    res += cross(g[i], g[(i+1)%n]);
  return res / 2;
}

bool is_polygon(const Polygon &g, Segment s) {
  int n = g.size();
  for (int i = 0; i < n; i++) {
    Point a = g[i], b = g[(i+1)%n];
    if (isis_ss(s, Segment(a, b))) return true;
  }
  return false;
}

int is_in_polygon(const Polygon &g, Point p) {
  bool in = false;
  int n = g.size();
  for (int i = 0; i < n; i++) {
    Point a = g[i] - p, b = g[(i+1)%n] - p;
    if (imag(a) > imag(b)) swap(a, b);
    if (imag(a) <= 0 && 0 < imag(b))
      if (cross(a, b) < 0) in = !in;
    if (abs(cross(a, b)) < eps && dot(a, b) < eps) return 0; // on
  }
  if(in) return 1; // in
  return -1; // out
}

Polygon convex_hull(vector<Point> ps) {
  int n = ps.size(), k = 0;
  sort(begin(ps), end(ps), comp);
  Polygon ch(2 * n);
  for (int i = 0; i < n; ch[k++] = ps[i++])
    while (k >= 2 && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
  for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = ps[i--])
    while (k >= t && ccw(ch[k - 2], ch[k - 1], ps[i]) <= 0) --k;
  ch.resize(k - 1);
  return ch;
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
{% endhighlight %}

- [Back](../../..)
