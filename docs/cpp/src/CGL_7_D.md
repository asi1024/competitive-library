{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_7_D.cpp)

{% highlight cpp %}
#include "../include/geometry/circle_intersect.cpp"

Point input() {
  ld x, y;
  scanf("%Lf%Lf", &x, &y);
  return Point(x, y);
}

int main() {
  ld cx, cy, r;
  scanf("%Lf%Lf%Lf", &cx, &cy, &r);
  Circle c(Point(cx, cy), r);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    Line l = Line(input(), input());
    vector<Point> res = is_cl(c, l);
    Point pa = res[0], pb = (res.size() == 2 ? res[1] : res[0]);
    if (real(pa) > real(pb) + eps ||
        (real(pa) > real(pb) - eps && imag(pa) > imag(pb))) swap(pa, pb);
    printf("%.10Lf %.10Lf %.10Lf %.10Lf\n",
           real(pa), imag(pa), real(pb), imag(pb));
  }
}
{% endhighlight %}

### Includes

- [circle_intersect.cpp](../include/geometry/circle_intersect)

[Back](..)
