{% include mathjax.html %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
Edge(int s, int t);
Edge(int t);
Edge(int t);
Edge(int t, Cost c);
Edge(int, int t);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/unweighted_graph.hpp)

{% highlight cpp %}
#include "definition.hpp"

class Edge {
public:
  using cost_type = int;
  int to;
  cost_type cost = 1;
  Edge(int, int t) : to(t) { ; }
};

using Graph = graph_t<Edge>;
{% endhighlight %}

### Includes

- [definition.hpp](definition)

[Back](../..)
