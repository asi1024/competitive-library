{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_2_A.cpp)

{% highlight cpp %}
#include "../include/geometry/intersect.cpp"

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
    if (!isis_ll(l1, l2))
      puts("2");
    else if (dot(l1.a - l1.b, l2.a - l2.b) == 0)
      puts("1");
    else
      puts("0");
  }
  return 0;
}
{% endhighlight %}

### Includes

- [intersect.cpp](../include/geometry/intersect)

[Back](..)
