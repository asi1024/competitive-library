#include "../include/geometry/circle_intersect.cpp"
#include "../include/geometry/circle_tangent.cpp"

Point input() {
  ld x, y;
  scanf("%Lf%Lf", &x, &y);
  return Point(x, y);
}

int main() {
  ld px, py, cx, cy, r;
  scanf("%Lf%Lf%Lf%Lf%Lf", &px, &py, &cx, &cy, &r);
  Point p(px, py);
  Circle c(Point(cx, cy), r);
  vector<Line> ls = tangent_cp(c, p);
  vector<Point> res;
  for (Line l : ls)
    res.push_back(proj(l, c.p));
  Point pa = res[0], pb = res[1];
  if (real(pa) > real(pb) + eps ||
      (real(pa) > real(pb) - eps && imag(pa) > imag(pb)))
    swap(pa, pb);
  printf("%.10Lf %.10Lf\n%.10Lf %.10Lf\n", real(pa), imag(pa), real(pb),
         imag(pb));
  return 0;
}
