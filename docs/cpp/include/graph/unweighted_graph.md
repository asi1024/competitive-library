{% include mathjax.html %}

## add_edge

{% highlight cpp %}
void add_edge(Graph &g, int from, int to);
{% endhighlight %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
Edge(int t);
Edge(int t);
Edge(int t, Cost c);
Edge(int s, int t);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/unweighted_graph.hpp)

{% highlight cpp %}
#include "definition.hpp"

class Edge {
public:
  using cost_type = int;
  int from, to;
  static const cost_type cost = 1;
  Edge(int s, int t) : from(s), to(t) { ; }
};

using Graph = graph_t<Edge>;

void add_edge(Graph &g, int from, int to) {
  g[from].emplace_back(from, to);
  g[to].emplace_back(to, from);
}
{% endhighlight %}

### Includes

- [definition.hpp](definition)

[Back](../..)
