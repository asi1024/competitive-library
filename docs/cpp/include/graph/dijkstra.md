## dijkstra.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/dijkstra.cpp)

{% highlight cpp %}
template <typename Cost>
struct Edge {
  int from, to;
  Cost cost;
  Edge(int s, int t, Cost c) : from(s), to(t), cost(c) {}
};

template<typename Cost> using Graph = vector<vector<Edge<Cost>>>;

template <typename Cost>
void add_edge(Graph<Cost> &g, int from, int to, Cost cost) {
  g[from].emplace_back(from, to, cost);
}

template <typename Cost>
vector<Cost> dijkstra(const Graph<Cost> &g, int s, Cost zero = 0) {
  vector<Cost> d(g.size(), inf<Cost>);
  d[s] = zero;
  using P = pair<Cost,int>;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(zero, s));
  while (!que.empty()) {
    Cost dist = que.top().first;
    int v = que.top().second;
    que.pop();
    if (d[v] < dist) continue;
    for (const auto &e: g[v]) {
      if (d[e.to] <= d[v] + e.cost) continue;
      d[e.to] = d[v] + e.cost;
      que.push(P(d[e.to], e.to));
    }
  }
  return d;
}
{% endhighlight %}

- [Back](../../../..)
