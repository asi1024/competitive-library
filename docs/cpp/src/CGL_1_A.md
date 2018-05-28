{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_1_A.cpp)

{% highlight cpp %}
#include "../include/geometry/intersect.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;

int main() {
  cout << setprecision(11) << fixed;
  P a, b, p;
  cin >> a >> b;
  L l(a, b);
  int q;
  cin >> q;
  while (q--) {
    cin >> p;
    P res = proj(l, p);
    cout << res << endl;
  }
}
{% endhighlight %}

### Includes

- [intersect.cpp](../include/geometry/intersect)

[Back](..)
