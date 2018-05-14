{% include mathjax.html %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
WeightedEdge(int, int t, cost_type c);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/weighted_graph.hpp)

{% highlight cpp %}
#include "definition.hpp"

template<typename Cost>
class WeightedEdge {
public:
  using cost_type = Cost;
  int to;
  cost_type cost;
  WeightedEdge(int, int t, cost_type c) : to(t), cost(c) {;}
};

template<typename Cost>
using WeightedGraph = graph_t<WeightedEdge<Cost>>;
{% endhighlight %}

### Includes

- [definition.hpp](definition)

[Back](../..)
