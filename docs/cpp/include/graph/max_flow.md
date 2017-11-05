## max_flow.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/max_flow.cpp)

{% highlight cpp %}
template <typename Edge>
typename Edge::Flow augment(vector<vector<Edge>> &g,
                            vector<int> &d, vector<int> &iter,
                            int v, int t, const typename Edge::Flow &f) {
  if (v == t) return f;
  for (int &i = iter[v]; i < (int)g[v].size(); i++) {
    auto &e = g[v][i];
    if (e.cap > 0 && d[v] < d[e.to]) {
      typename Edge::Flow ff = augment(g, d, iter, e.to, t, min(f, e.cap));
      if (ff > 0) {
        e.cap -= ff;
        g[e.to][e.rev].cap += ff;
        return ff;
      }
    }
  }
  return 0;
}

template <typename Edge>
typename Edge::Flow max_flow(vector<vector<Edge>> &g, int s, int t,
                             typename Edge::Flow zero = 0) {
  using Flow = typename Edge::Flow;
  const int V = g.size();
  Flow flow = zero;
  for (;;) {
    vector<int> d(V, -1);
    queue<int> que;
    d[s] = zero;
    que.push(s);
    while(!que.empty()) {
      int v = que.front(); que.pop();
      for (const auto &e: g[v]) {
        if (e.cap <= zero || d[e.to] >= zero) continue;
        d[e.to] = d[v] + 1;
        que.push(e.to);
      }
    }
    if (d[t] < zero) return flow;
    vector<int> iter(V, 0);
    Flow f;
    while ((f = augment(g, d, iter, s, t, inf<Flow>)) > 0) flow += f;
  }
}

struct Edge {
  using Flow = int;
  int from, to, rev;
  Flow cap;
  Edge(int s, int t, Flow f, int r) : from(s), to(t), rev(r), cap(f) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to, Edge::Flow cap) {
  g[from].emplace_back(from, to, cap, (int)g[to].size());
  g[to].emplace_back(to, from, 0, (int)g[from].size() - 1);
}
{% endhighlight %}

- [Back](../../..)
