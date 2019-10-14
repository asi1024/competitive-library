## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_2_B.cpp)

{% highlight cpp %}
#include "../include/geometry/intersect.cpp"

using namespace std;

using P = Point<float11>;
using S = Segment<float11>;

int main() {
  int q;
  cin >> q;
  while (q--) {
    P a, b, c, d;
    cin >> a >> b >> c >> d;
    S s1(a, b), s2(c, d);
    if (isis_ss(s1, s2))
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
