## CGL_1_C.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_1_C.cpp)

### Include

- [Geometry.hpp](../include/geometry/Geometry.hpp)

{% highlight cpp %}
#include "../include/geometry/Geometry.hpp"

Point input() {
  ld x, y;
  scanf("%Lf%Lf", &x, &y);
  return Point(x, y);
}

int main() {
  Point p0 = input();
  Point p1 = input();
  int q;
  scanf("%d", &q);
  while (q--) {
    Point p2 = input();
    int c = ccw(p0, p1, p2);
    switch(c) {
    case 1:  puts("COUNTER_CLOCKWISE"); break;
    case -1: puts("CLOCKWISE"); break;
    case 2:  puts("ONLINE_BACK"); break;
    case -2: puts("ONLINE_FRONT"); break;
    case 0:  puts("ON_SEGMENT"); break;
    }
  }
  return 0;
}
{% endhighlight %}

- [Back](../..)
