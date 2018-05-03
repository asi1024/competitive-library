

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_1_A.cpp)

{% highlight cpp %}
#include "../include/geometry/intersect.cpp"

Point input() {
  ld x, y;
  scanf("%Lf%Lf", &x, &y);
  return Point(x, y);
}

int main() {
  Line l(input(), input());
  int q;
  scanf("%d", &q);
  while (q--) {
    Point p = input();
    Point res = proj(l, p);
    printf("%.10Lf %.10Lf\n", real(res), imag(res));
  }
}
{% endhighlight %}

### Includes

- [intersect.cpp](../include/geometry/intersect)

[Back](..)
