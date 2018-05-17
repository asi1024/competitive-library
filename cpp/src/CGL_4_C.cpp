#include "../include/geometry/convex.cpp"
#include "../include/geometry/polygon.cpp"

Point input() {
  ld x, y;
  scanf("%Lf%Lf", &x, &y);
  return Point(x, y);
}

int main() {
  int n, q;
  scanf("%d", &n);
  Polygon poly;
  for (int i = 0; i < n; ++i) {
    poly.push_back(input());
  }
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    Point p1 = input();
    Point p2 = input();
    bool is_zero = true, is_one = true;
    for (int j = 0; j < n; ++j) {
      int c = ccw(p1, p2, at(poly, j));
      if (c == 1)
        is_zero = false;
      if (c == -1)
        is_one = false;
    }
    Polygon g = convex_cut(poly, Line(p1, p2));
    ld res = is_zero ? 0.0L : (is_one ? area(poly) : area(g));
    printf("%.10Lf\n", res);
  }
}
