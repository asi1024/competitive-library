{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_7_G.cpp)

{% highlight cpp %}
#include "../include/geometry/circle_intersect.cpp"
#include "../include/geometry/circle_tangent.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;
using C = Circle<float11>;

int main() {
  cout << setprecision(12) << fixed;
  P p1, p2;
  float11 r1, r2;
  cin >> p1 >> r1 >> p2 >> r2;
  C c1(p1, r1), c2(p2, r2);
  vector<L> ls = tangent_cc(c1, c2);
  vector<P> res;
  for (L l : ls) res.push_back(proj(l, c1.p));
  sort(begin(res), end(res));
  for (P p : res) cout << p << endl;
  return 0;
}
{% endhighlight %}

### Includes

- [circle_intersect.cpp](../include/geometry/circle_intersect)
- [circle_tangent.cpp](../include/geometry/circle_tangent)

[Back](..)
