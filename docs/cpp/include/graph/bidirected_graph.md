---
title: "bidirected_graph.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/bidirected_graph.cpp)

{% highlight cpp %}
#include "definition.cpp"

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

- [definition.cpp](definition)

[Back](../..)
