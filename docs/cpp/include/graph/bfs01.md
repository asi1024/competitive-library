## bfs01.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/bfs01.cpp)

{% highlight cpp %}
template <typename Edge>
vector<typename Edge::Cost> bfs01(const vector<vector<Edge>> &g, int s) {
  using Cost = typename Edge::Cost;
  vector<Cost> d(g.size(), inf<Cost>);
  d[s] = 0;
  deque<pair<Cost,int>> que;
  que.emplace_back(0, s);
  while (!que.empty()) {
    auto top = que.front();
    que.pop_front();
    Cost dist = top.first; int v = top.second;
    if (d[v] < dist) continue;
    for (const auto &e: g[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        if (e.cost == 1) que.emplace_back(d[e.to], e.to);
        else if (e.cost == 0) que.emplace_front(d[e.to], e.to);
        else assert(false);
      }
    }
  }
  return d;
}

struct Edge {
  using Cost = int;
  int to;
  Cost cost;
  Edge(int t, Cost c) : to(t), cost(c) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to, Edge::Cost cost) {
  g[from].emplace_back(to, cost);
}
{% endhighlight %}

- [Back](../../..)
