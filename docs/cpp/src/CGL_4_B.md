{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/CGL_4_B.cpp)

{% highlight cpp %}
#include "../include/geometry/convex.cpp"

using namespace std;

using P = Point<float11>;

int main() {
  cout << setprecision(12) << fixed;
  int n;
  cin >> n;
  std::vector<P> ps;
  for (int i = 0; i < n; ++i) {
    P p;
    cin >> p;
    ps.push_back(p);
  }
  cout << max_distance(ps) << endl;
}
{% endhighlight %}

### Includes

- [convex.cpp](../include/geometry/convex)

[Back](..)
