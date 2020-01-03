---
title: "aoj-CGL_4_C.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/aoj-CGL_4_C.cpp)

{% highlight cpp %}
#include "../include/geometry/convex.cpp"
#include "../include/template/initialize.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;
using G = Polygon<float11>;

int main() {
  int n, q;
  cin >> n;
  G poly;
  for (int i = 0; i < n; ++i) {
    P p;
    cin >> p;
    poly.push_back(p);
  }
  cin >> q;
  for (int i = 0; i < q; ++i) {
    P p1, p2;
    cin >> p1 >> p2;
    bool is_zero = true, is_one = true;
    for (int j = 0; j < n; ++j) {
      int c = ccw(p1, p2, poly[j]);
      if (c == 1) is_zero = false;
      if (c == -1) is_one = false;
    }
    G g = convex_cut(poly, L(p1, p2));
    cout << (is_zero ? 0.0L : (is_one ? area(poly) : area(g))) << endl;
  }
}
{% endhighlight %}

### Includes

- [convex.cpp](../include/geometry/convex)
- [initialize.cpp](../include/template/initialize)

[Back](..)
