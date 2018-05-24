{% include mathjax.html %}

## add_edge

{% highlight cpp %}
void add_edge(BidirectedGraph &g, int from, int to);
{% endhighlight %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
BidirectedEdge(int s, int t);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/bidirected_graph.hpp)

{% highlight cpp %}
#include "definition.hpp"

class BidirectedEdge {
public:
  using cost_type = int;
  int from, to;
  static const cost_type cost = 1;
  BidirectedEdge(int s, int t) : from(s), to(t) { ; }
};

using BidirectedGraph = graph_t<BidirectedEdge>;

void add_edge(BidirectedGraph &g, int from, int to) {
  g[from].emplace_back(from, to);
  g[to].emplace_back(to, from);
}
{% endhighlight %}

### Includes

- [definition.hpp](definition)

[Back](../..)
