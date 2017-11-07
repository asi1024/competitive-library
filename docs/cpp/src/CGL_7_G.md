## CGL_7_G.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_7_G.cpp)

### Includes

- [circle_intersect.cpp](../include/geometry/circle_intersect)
- [circle_tangent.cpp](../include/geometry/circle_tangent)

{% highlight cpp %}
#include "../include/geometry/circle_intersect.cpp"
#include "../include/geometry/circle_tangent.cpp"

Point input() {
  ld x, y;
  scanf("%Lf%Lf", &x, &y);
  return Point(x, y);
}

bool compare(const Point &p, const Point &q) {
  return real(p) < real(q) - eps ||
                   (real(p) < real(q) + eps && imag(p) < imag(q));
}

int main() {
  ld x1, y1, r1, x2, y2, r2;
  scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &x1, &y1, &r1, &x2, &y2, &r2);
  Circle c1(Point(x1, y1), r1), c2(Point(x2, y2), r2);
  vector<Line> ls = tangent_cc(c1, c2);
  vector<Point> res;
  for (Line l: ls) res.push_back(proj(l, c1.p));
  sort(begin(res), end(res), compare);
  for (Point p: res) {
    printf("%.10Lf %.10Lf\n", real(p), imag(p));
  }
  return 0;
}
{% endhighlight %}

[Back](../..)
