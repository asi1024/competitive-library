## Geometry.hpp

- [GitHub]({{ site.github.repository_url }}/bolb/master/cpp/include/geometry/Geometry.hpp)

```cpp
using Point = complex<ld>;
using Polygon = vector<Point>;

const ld eps = 1e-10;

Point at(const Polygon &g, int i) {
  i %= (int)g.size();
  return g[i < 0 ? i + g.size() : i];
}

bool comp(Point a, Point b) {
  return real(a - b) * 1.347589 + imag(a - b) > 0;
}

ld dot(Point a, Point b) { return real(conj(a) * b); }
ld cross(Point a, Point b) { return imag(conj(a) * b); }

struct Segment {
  Point a, b;
  Segment (Point p, Point q) : a(p), b(q) {;}
};

struct Line {
  Point a, b;
  Line (Point p, Point q) : a(p), b(q) {;}
  explicit Line (Segment s) : a(s.a), b(s.b) {;}
};

struct Circle {
  Point p; ld r;
  Circle (Point a, ld b) : p(a), r(b) {;}
};

// counter clockwise
int ccw (Point a, Point b, Point c) {
  b -= a; c -= a;
  if (cross(b, c) > eps) return 1;   // counter clockwise
  if (cross(b, c) < -eps) return -1; // clockwise
  if (dot(b, c) < 0) return 2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line
  return 0;                          // a--c--b on line
}

vector<Point> unique(vector<Point> ps) {
  sort(begin(ps), end(ps), comp);
  vector<Point> res;
  for (Point p: ps)
    if (res.empty() || abs(res.back() - p) > eps)
      res.push_back(p);
  return res;
}
```

- [Back](https://{{ site.github.owner_name }}.github.io/competitive-library)
