## scc.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/scc.cpp)

{% highlight cpp %}
struct Edge {
  int to;
  Edge(int t) : to(t) {}
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph &g, int from, int to) {
  g[from].emplace_back(to);
}

class scc {
  const int n;
  int k;
  vector<vector<int>> g, rg;
  vector<int> cmp, vs, used;
  void dfs(const int v) {
    used[v] = true;
    for (int i: g[v]) if (!used[i]) dfs(i);
    vs.push_back(v);
  };
  void rdfs(const int v, const int k) {
    used[v] = true; cmp[v] = k;
    for (int i: rg[v]) if (!used[i]) rdfs(i, k);
  };
public:
  scc(const Graph &graph) : n(graph.size()), k(0), g(n), rg(n), cmp(n), used(n, 0) {
    for (int i = 0; i < n; ++i) {
      for (Edge e: graph[i]) {
        g[i].push_back(e.to);
        rg[e.to].push_back(i);
      }
    }
    for (int v = 0; v < n; ++v) if (!used[v]) dfs(v);
    fill(begin(used), end(used), 0);
    reverse(begin(vs), end(vs));
    for (int i: vs) if (!used[i]) rdfs(i, k++);
  }
  operator vector<int>() const { return cmp; }
};
{% endhighlight %}

- [Back](../../..)
