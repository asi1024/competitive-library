---
title: "articulation_points.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/articulation_points.cpp)

{% highlight cpp %}
#include "definition.hpp"

template <typename edge_t>
std::pair<std::set<int>, std::vector<std::vector<edge_t>>>
articulation_points(const graph_t<edge_t> &g) {
  const int n = g.size();
  std::set<int> art;
  std::vector<std::vector<edge_t>> connect;
  std::vector<edge_t> st;
  std::vector<int> order(n, -1), low(n, -1);
  for (int i = 0; i < n; i++) {
    if (order[i] != -1) continue;
    int cnt = 0;
    std::function<void(int, int)> dfs = [&](int from, int parent) {
      low[from] = order[from] = cnt++;
      for (edge_t e : g[from]) {
        const int to = e.to;
        if (to != parent && order[to] < order[from]) st.push_back(e);
        if (order[to] == -1) {
          dfs(to, from);
          low[from] = std::min(low[from], low[to]);
          if ((order[from] == 0 && order[to] != 1) ||
              (order[from] != 0 && low[to] >= order[from]))
            art.insert(from);
          if (low[to] >= order[from]) {
            connect.push_back(std::vector<edge_t>());
            for (;;) {
              edge_t edge = st.back();
              st.pop_back();
              connect.back().push_back(edge);
              if (edge.from == from && edge.to == to) break;
            }
          }
        }
        else {
          low[from] = std::min(low[from], order[to]);
        }
      }
    };
    dfs(i, i);
  }
  return make_pair(move(art), move(connect));
}
{% endhighlight %}

### Includes

- [definition.hpp](definition)

[Back](../..)
