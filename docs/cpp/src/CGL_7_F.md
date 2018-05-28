{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_7_F.cpp)

{% highlight cpp %}
#include "../include/geometry/circle_intersect.cpp"
#include "../include/geometry/circle_tangent.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;
using C = Circle<float11>;

int main() {
  cout << setprecision(12) << fixed;
  P p, cp;
  float11 r;
  cin >> p >> cp >> r;
  const C c(cp, r);
  vector<L> ls = tangent_cp(c, p);
  vector<P> res;
  for (L l : ls) res.push_back(proj(l, c.p));
  P pa = res[0], pb = res[1];
  if (pa > pb) swap(pa, pb);
  cout << pa << endl << pb << endl;
  return 0;
}
{% endhighlight %}

### Includes

- [circle_intersect.cpp](../include/geometry/circle_intersect)
- [circle_tangent.cpp](../include/geometry/circle_tangent)

[Back](..)
