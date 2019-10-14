---
title: "CGL_3_A.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_3_A.cpp)

{% highlight cpp %}
#include "../include/geometry/polygon.cpp"
#include "../include/template/initialize.cpp"

using namespace std;

using P = Point<float11>;
using G = Polygon<float11>;

int main() {
  int n;
  cin >> n;
  G poly;
  for (int i = 0; i < n; ++i) {
    P p;
    cin >> p;
    poly.push_back(p);
  }
  cout << area(poly) << endl;
}
{% endhighlight %}

### Includes

- [polygon.cpp](../include/geometry/polygon)
- [initialize.cpp](../include/template/initialize)

[Back](..)
