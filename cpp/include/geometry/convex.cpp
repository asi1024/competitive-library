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
