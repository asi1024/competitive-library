## max_flow.cpp

```cpp
template <typename Flow>
struct Edge {
  int from, to;
  Flow cap; int rev;
  Edge(int s, int t, Flow f, int r) : from(s), to(t), cap(f), rev(r) {}
};

template<typename Flow> using Graph = vector<vector<Edge<Flow>>>;

template <typename Flow>
void add_edge(Graph<Flow> &g, int from, int to, Flow cap) {
  g[from].emplace_back(from, to, cap, (int)g[to].size());
  g[to].emplace_back(to, from, 0, (int)g[from].size() - 1);
}

template <typename Flow>
Flow augment(Graph<Flow> &g, vector<Flow> &d, vector<int> &iter,
             int v, int t, const Flow &f) {
  if (v == t) return f;
  for (int &i = iter[v]; i < (int)g[v].size(); i++) {
    auto &e = g[v][i];
    if (e.cap > 0 && d[v] < d[e.to]) {
      Flow ff = augment(g, d, iter, e.to, t, min(f, e.cap));
      if (ff > 0) {
        e.cap -= ff;
        g[e.to][e.rev].cap += ff;
        return ff;
      }
    }
  }
  return 0;
}

template <typename Flow>
Flow max_flow(Graph<Flow> &g, int s, int t, Flow zero = 0) {
  const int V = g.size();
  Flow flow = zero;
  for (;;) {
    vector<Flow> d(V, -1);
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
```

- [Back](../)
