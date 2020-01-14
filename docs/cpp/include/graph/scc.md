---
title: "scc.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/scc.cpp)

{% highlight cpp %}
#include "../template/includes.cpp"
#include "definition.cpp"

template <typename edge_t> struct scc_struct {
  const int n;
  const graph_t<edge_t> g;
  std::vector<std::vector<int>> rg;
  std::vector<int> cmp, vs;
  std::vector<bool> used;
  void dfs(int v) {
    used[v] = true;
    for (edge_t e : g[v])
      if (!used[e.to]) dfs(e.to);
    vs.push_back(v);
  };
  void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int i : rg[v])
      if (!used[i]) rdfs(i, k);
  };
  scc_struct(const graph_t<edge_t> &g_) :
    n(g_.size()), g(g_), rg(n), cmp(n), vs(0), used(n, false) {
    for (int i = 0; i < n; ++i) {
      for (edge_t e : g[i]) {
        rg[e.to].push_back(i);
      }
    }
    for (int v = 0; v < n; ++v) {
      if (!used[v]) dfs(v);
    }
    std::fill(begin(used), end(used), false);
    std::reverse(begin(vs), end(vs));
    int k = 0;
    for (int i : vs)
      if (!used[i]) rdfs(i, k++);
  }
};

template <typename edge_t> std::vector<int> scc(const graph_t<edge_t> &g) {
  scc_struct<edge_t> s(g);
  return s.cmp;
}
{% endhighlight %}

### Includes

- [includes.cpp](../template/includes)
- [definition.cpp](definition)

[Back](../..)
