## spfa.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/spfa.cpp)

```cpp
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
pair<bool,vector<Cost>> spfa(const Graph<Cost> &g, int s, Cost zero = 0) {
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
```

- [Back](../../../..)
