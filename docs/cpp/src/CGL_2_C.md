## CGL_2_C.cpp

```
Point input() {
  ld x, y;
  scanf("%Lf%Lf", &x, &y);
  return Point(x, y);
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    Line l1(input(), input());
    Line l2(input(), input());
    Point res = is_ll(l1, l2);
    printf("%.10Lf %.10Lf\n", real(res), imag(res));
  }
  return 0;
}
```

- [Back](../)
