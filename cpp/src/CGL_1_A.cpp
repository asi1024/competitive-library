#include "../include/intersect.cpp"

Point input() {
  ld x, y;
  scanf("%Lf%Lf", &x, &y);
  return Point(x, y);
}

int main() {
  Line l = Line(input(), input());
  int q;
  scanf("%d", &q);
  while (q--) {
    Point p = input();
    Point res = proj(l, p);
    printf("%.10Lf %.10Lf\n", real(res), imag(res));
  }
}
