## spfa.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/spfa.cpp)

{% highlight cpp %}
template <typename Edge>
pair<bool,vector<typename Edge::Cost>> spfa(const vector<vector<Edge>> &g, int s,
                                            typename Edge::Cost zero = 0) {
  using Cost = typename Edge::Cost;
  const int n = g.size();
  vector<Cost> d(n, inf<Cost>); d[s] = zero;
  vector<int> updated(n, 0);
  vector<bool> inque(n, false);
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int from = que.front();
    que.pop();
    inque[from] = false;
    ++updated[from];
    if (updated[from] == n + 1) return {false, d}; // negative cycle
    for (const auto &e: g[from]) {
      Cost cost = d[from] + e.cost;
      if (cost < d[e.to]) {
        d[e.to] = cost;
        if (!inque[e.to]) {
          que.push(e.to);
          inque[e.to] = true;
        }
      }
    }
  }
  return {true, d};
}

struct Edge {
  using Cost = int;
  int from, to;
  Cost cost;
  Edge(int s, int t, Cost c) : from(s), to(t), cost(c) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to, Edge::Cost cost) {
  g[from].emplace_back(from, to, cost);
}
{% endhighlight %}

- [Back](../../..)
