{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_7_D.cpp)

{% highlight cpp %}
#include "../include/geometry/circle_intersect.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;
using C = Circle<float11>;

int main() {
  cout << setprecision(12) << fixed;
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

[Back](..)
