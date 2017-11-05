## scc.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/scc.cpp)

{% highlight cpp %}
template<typename Edge>
vector<int> scc(const vector<vector<Edge>> &g) {
  const int n = g.size();
  vector<vector<int>> rg(n);
  vector<int> cmp(n), vs;
  vector<bool> used(n, false);
  for (int i = 0; i < n; ++i) {
    for (Edge e: g[i]) {
      rg[e.to].push_back(i);
    }
  }
  function<void(int)> dfs = [&](int v) {
    used[v] = true;
    for (Edge e: g[v]) if (!used[e.to]) dfs(e.to);
    vs.push_back(v);
  };
  function<void(int,int)> rdfs = [&](int v, int k) {
    used[v] = true; cmp[v] = k;
    for (int i: rg[v]) if (!used[i]) rdfs(i, k);
  };
  for (int v = 0; v < n; ++v) {
    if (!used[v]) dfs(v);
  }
  used = vector<bool>(n, false);
  reverse(begin(vs), end(vs));
  int k = 0;
  for(int i: vs) if (!used[i]) rdfs(i, k++);
  return cmp;
}

struct Edge {
  int to;
  Edge(int t) : to(t) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to) {
  g[from].emplace_back(to);
}
{% endhighlight %}

- [Back](../../..)
