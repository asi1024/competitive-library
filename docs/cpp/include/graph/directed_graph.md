{% include mathjax.html %}

## add_edge

{% highlight cpp %}
void add_edge(DirectedGraph &g, int from, int to);
{% endhighlight %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
DirectedEdge(int, int t);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/directed_graph.hpp)

{% highlight cpp %}
#include "definition.hpp"

class DirectedEdge {
public:
  using cost_type = int;
  int to;
  static const cost_type cost = 1;
  DirectedEdge(int, int t) : to(t) { ; }
};

using DirectedGraph = graph_t<DirectedEdge>;

void add_edge(DirectedGraph &g, int from, int to) {
  g[from].emplace_back(from, to);
}
{% endhighlight %}

### Includes

- [definition.hpp](definition)

[Back](../..)
