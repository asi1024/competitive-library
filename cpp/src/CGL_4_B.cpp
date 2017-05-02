#include "../include/geometry/convex.cpp"

Point input() {
  ld x, y;
  scanf("%Lf%Lf", &x, &y);
  return Point(x, y);
}

int main() {
  int n;
  scanf("%d", &n);
  Polygon poly;
  for (int i = 0; i < n; ++i) {
    poly.push_back(input());
  }
  printf("%.10Lf\n", max_distance(poly));
}
