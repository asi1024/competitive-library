### Includes

- [polygon.cpp](../include/geometry/polygon)

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_3_A.cpp)

{% highlight cpp %}
#include "../include/geometry/polygon.cpp"

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
  printf("%.10Lf\n", area(poly));
}
{% endhighlight %}

[Back](..)
