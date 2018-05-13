{% include mathjax.html %}

## add_edge

{% highlight cpp %}
void add_edge(Graph &g, int from, int to);
{% endhighlight %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
LCA(const vector< vector< Edge >> &g, int root);
{% endhighlight %}


---------------------------------------

### [2] query
{% highlight cpp %}
int query(int u, int v);
{% endhighlight %}


---------------------------------------

## Member functions

### [1] (constructor)
{% highlight cpp %}
Edge(int s, int t);
Edge(int t, Cost c);
Edge(int t);
Edge(int t, Flow f, int r);
Edge(int t, Flow f, int r, Cost c);
Edge(int t);
Edge(int t, Cost c);
Edge(int t);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/lca.cpp)

{% highlight cpp %}
#include "../util.hpp"

class LCA {
  int size, log_size;
  vector<vector<int>> parent;
  vector<int> depth;
  template <typename Edge>
  void dfs(const vector<vector<Edge>> &g, int v, int p, int d) {
    parent[0][v] = p; depth[v] = d;
    for (const Edge &e: g[v]) {
      if (e.to != p) dfs(g, e.to, v, d + 1);
    }
  }
public:
  template <typename Edge>
  LCA(const vector<vector<Edge>> &g, int root) : size(g.size()), log_size(0), depth(size, 0) {
    for (int v = size; v > 0; v /= 2) ++log_size;
    parent.assign(log_size, vector<int>(size, 0));
    dfs(g, root, -1, 0);
    for (int k = 0; k < log_size - 1; ++k) {
      for (int v = 0; v < size; ++v) {
        if (parent[k][v] < 0) parent[k + 1][v] = -1;
        else parent[k + 1][v] = parent[k][parent[k][v]];
      }
    }
  }
  int query(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
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

struct Edge {
  int to;
  Edge(int t) : to(t) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to) {
  g[from].push_back(to);
}
{% endhighlight %}

### Includes

- [util.hpp](../util)

[Back](../..)
