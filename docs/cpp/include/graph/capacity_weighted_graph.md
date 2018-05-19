{% include mathjax.html %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
CapacityWeightedEdge(int, int t, int r, capacity_type f, cost_type c);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/capacity_weighted_graph.hpp)

{% highlight cpp %}
#include "definition.hpp"

template <typename Capacity, typename Cost> class CapacityWeightedEdge {
public:
  using capacity_type = Capacity;
  using cost_type = Cost;
  int to, rev;
  capacity_type cap;
  cost_type cost;
  CapacityWeightedEdge(int, int t, int r, capacity_type f, cost_type c)
      : to(t), rev(r), cap(f), cost(c) {
    ;
  }
};

template <typename Capacity, typename Cost>
using CapacityWeightedGraph = graph_t<CapacityWeightedEdge<Capacity, Cost>>;
{% endhighlight %}

### Includes

- [definition.hpp](definition)

[Back](../..)
