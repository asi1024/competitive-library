### Includes

- [circle_intersect.cpp](../include/geometry/circle_intersect)

{% highlight cpp %}
#include "../include/geometry/circle_intersect.cpp"

Point input() {
  ld x, y;
  scanf("%Lf%Lf", &x, &y);
  return Point(x, y);
}

int main() {
  ld x1, y1, r1, x2, y2, r2;
  scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &x1, &y1, &r1, &x2, &y2, &r2);
  Circle c1(Point(x1, y1), r1), c2(Point(x2, y2), r2);
  vector<Point> res = is_cc(c1, c2);
  Point pa = res[0], pb = (res.size() == 2 ? res[1] : res[0]);
  if (real(pa) > real(pb) + eps ||
      (real(pa) > real(pb) - eps && imag(pa) > imag(pb))) swap(pa, pb);
  printf("%.10Lf %.10Lf %.10Lf %.10Lf\n",
         real(pa), imag(pa), real(pb), imag(pb));
  return 0;
}
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_7_E.cpp)

[Back](..)
