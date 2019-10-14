---
title: "CGL_2_C.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_2_C.cpp)

{% highlight cpp %}
#include "../include/geometry/intersect.cpp"
#include "../include/template/initialize.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;

int main() {
  int q;
  cin >> q;
  while (q--) {
    P a, b, c, d;
    cin >> a >> b >> c >> d;
    L l1(a, b), l2(c, d);
    P res = is_ll(l1, l2);
    cout << res << endl;
  }
  return 0;
}
{% endhighlight %}

### Includes

- [intersect.cpp](../include/geometry/intersect)
- [initialize.cpp](../include/template/initialize)

[Back](..)
