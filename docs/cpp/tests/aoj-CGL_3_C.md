---
title: "aoj-CGL_3_C.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/aoj-CGL_3_C.cpp)

{% highlight cpp %}
#include "../include/geometry/polygon.cpp"

using namespace std;

using P = Point<float11>;
using G = Polygon<float11>;

int main() {
  int n, q;
  cin >> n;
  G poly;
  P p;
  for (int i = 0; i < n; ++i) {
    cin >> p;
    poly.push_back(p);
  }
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> p;
    cout << is_in_polygon(poly, p) + 1 << endl;
  }
}
{% endhighlight %}

### Includes

- [polygon.cpp](../include/geometry/polygon)

[Back](..)
