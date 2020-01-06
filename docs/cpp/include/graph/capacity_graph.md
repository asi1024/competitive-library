---
title: "capacity_graph.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/capacity_graph.cpp)

{% highlight cpp %}
#include "definition.cpp"

template <typename Capacity> class CapacityEdge {
public:
  using capacity_type = Capacity;
  int to, rev;
  capacity_type cap;
  CapacityEdge(int, int t, int r, capacity_type f) : to(t), rev(r), cap(f) { ; }
};

template <typename Capacity>
using CapacityGraph = graph_t<CapacityEdge<Capacity>>;

template <typename Capacity>
void add_edge(CapacityGraph<Capacity> &g, int from, int to, Capacity cap) {
  g[from].emplace_back(from, to, (int)g[to].size(), cap);
  g[to].emplace_back(to, from, (int)g[from].size() - 1, zero<Capacity>());
}
{% endhighlight %}

### Includes

- [definition.cpp](definition)

[Back](../..)
