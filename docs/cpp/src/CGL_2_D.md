## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_2_D.cpp)

{% highlight cpp %}
#include "../include/geometry/distance.cpp"
#include "../include/template/initialize.cpp"

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
    cout << dist_ss(s1, s2) << endl;
  }
  return 0;
}
{% endhighlight %}

### Includes

- [distance.cpp](../include/geometry/distance)
- [initialize.cpp](../include/template/initialize)

[Back](..)
