---
title: "directed_graph.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/directed_graph.cpp)

{% highlight cpp %}
#include "definition.cpp"

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

- [definition.cpp](definition)

[Back](../..)
