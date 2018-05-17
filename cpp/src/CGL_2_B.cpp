#include "../include/geometry/intersect.cpp"

Point input() {
  ld x, y;
  scanf("%Lf%Lf", &x, &y);
  return Point(x, y);
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    Segment s1(input(), input());
    Segment s2(input(), input());
    if (isis_ss(s1, s2))
      puts("1");
    else
      puts("0");
  }
  return 0;
}
