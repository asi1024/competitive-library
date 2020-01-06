---
title: "lca.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/lca.cpp)

{% highlight cpp %}
#include "definition.cpp"

class LCA {
  const int size;
  int log_size;
  std::vector<std::vector<int>> parent;
  std::vector<int> depth;
  template <typename edge_t>
  void dfs(const graph_t<edge_t> &g, int v, int p, int d) {
    parent[0][v] = p;
    depth[v] = d;
    for (const edge_t &e : g[v]) {
      if (e.to != p) dfs(g, e.to, v, d + 1);
    }
  }

public:
  template <typename edge_t>
  LCA(const graph_t<edge_t> &g, const int root) :
    size(g.size()), log_size(0), depth(size, 0) {
    for (int v = size; v > 0; v /= 2) ++log_size;
    parent.assign(log_size, std::vector<int>(size, 0));
    dfs(g, root, -1, 0);
    for (int k = 0; k < log_size - 1; ++k) {
      for (int v = 0; v < size; ++v) {
        if (parent[k][v] < 0)
          parent[k + 1][v] = -1;
        else
          parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
  int query(int u, int v) {
    if (depth[u] > depth[v]) std::swap(u, v);
    for (int k = 0; k < log_size; ++k)
      if (((depth[v] - depth[u]) >> k) & 1) v = parent[k][v];
    if (u == v) return u;
    for (int k = log_size - 1; k >= 0; k--) {
      if (parent[k][u] != parent[k][v]) {
        u = parent[k][u];
        v = parent[k][v];
      }
    }
    return parent[0][u];
  }
};
{% endhighlight %}

### Includes

- [definition.cpp](definition)

[Back](../..)
