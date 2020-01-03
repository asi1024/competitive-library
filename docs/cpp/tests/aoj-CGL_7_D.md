---
title: "aoj-CGL_7_D.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/aoj-CGL_7_D.cpp)

{% highlight cpp %}
#include "../include/geometry/circle_intersect.cpp"
#include "../include/template/initialize.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;
using C = Circle<float11>;

int main() {
  float11 cx, cy, r;
  cin >> cx >> cy >> r;
  C c(P(cx, cy), r);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    P la, lb;
    cin >> la >> lb;
    L l(la, lb);
    vector<P> res = is_cl(c, l);
    P pa = res[0], pb = (res.size() == 2 ? res[1] : res[0]);
    if (pa > pb) swap(pa, pb);
    cout << pa << " " << pb << endl;
  }
}
{% endhighlight %}

### Includes

- [circle_intersect.cpp](../include/geometry/circle_intersect)
- [initialize.cpp](../include/template/initialize)

[Back](..)
