{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/GRL_3_A.cpp)

{% highlight cpp %}
#include "../include/graph/articulation_points.cpp"
#include "../include/graph/unweighted_graph.hpp"

using namespace std;

int main() {
  int V, E, s, t;
  scanf("%d%d", &V, &E);
  Graph g(V);
  while (E--) {
    scanf("%d%d", &s, &t);
    add_edge(g, s, t);
  }
  set<int> art = articulation_points(g).first;
  for (int i : art) printf("%d\n", i);
  return 0;
}
{% endhighlight %}

### Includes

- [articulation_points.cpp](../include/graph/articulation_points)
- [unweighted_graph.hpp](../include/graph/unweighted_graph)

[Back](..)
