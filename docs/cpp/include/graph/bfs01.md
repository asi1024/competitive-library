---
title: "bfs01.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/bfs01.cpp)

{% highlight cpp %}
#include "../template/const_value.cpp"
#include "definition.cpp"

template <typename edge_t, typename cost_type = typename edge_t::cost_type>
std::vector<cost_type> bfs01(const graph_t<edge_t> &g, int s) {
  static_assert(std::is_integral<cost_type>::value, "cost must be integer");
  std::vector<cost_type> d(g.size(), inf<cost_type>());
  d[s] = cost_type(0);
  std::deque<std::pair<cost_type, int>> que;
  que.emplace_back(zero<cost_type>(), s);
  while (!que.empty()) {
    auto top = que.front();
    que.pop_front();
    cost_type dist = top.first;
    int v = top.second;
    if (d[v] < dist) continue;
    for (const auto &e : g[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        if (e.cost == cost_type(1)) {
          que.emplace_back(d[e.to], e.to);
        }
        else if (e.cost == cost_type(0)) {
          que.emplace_front(d[e.to], e.to);
        }
        else {
          assert(false);
        }
      }
    }
  }
  return d;
}
{% endhighlight %}

### Includes

- [const_value.cpp](../template/const_value)
- [definition.cpp](definition)

[Back](../..)
