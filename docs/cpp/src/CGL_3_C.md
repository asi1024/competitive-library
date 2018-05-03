

### Includes

- [polygon.cpp](../include/geometry/polygon)

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_3_C.cpp)

{% highlight cpp %}
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
    printf("%d\n", is_in_polygon(poly, input()) + 1);
  }
}
{% endhighlight %}

[Back](..)
