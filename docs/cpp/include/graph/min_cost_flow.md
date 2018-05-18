{% include mathjax.html %}

## min_cost_flow

{% highlight cpp %}
Cost min_cost_flow(vector< vector< Edge >> &g, int s, int t, Flow f, bool init=true);
{% endhighlight %}

## add_edge

{% highlight cpp %}
void add_edge(Graph &g, int from, int to, Edge::Flow cap, Edge::Cost cost);
{% endhighlight %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
Edge(int s, int t);
Edge(int t);
Edge(int t, Flow f, int r, Cost c);
Edge(int t);
Edge(int t, Cost c);
Edge(int, int t);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/min_cost_flow.cpp)

{% highlight cpp %}
#include "../util.hpp"

template <typename Edge, typename Flow = typename Edge::Flow,
          typename Cost = typename Edge::Cost>
Cost min_cost_flow(vector<vector<Edge>> &g, int s, int t, Flow f,
                   bool init = true) {
  const int V = g.size();
  // const Cost eps = 1e-8;
  static vector<Cost> h(V, 0), dist(V, 0);
  static vector<int> prevv(V), preve(V);
  if (init) {
    fill(begin(h), end(h), 0);
    fill(begin(dist), end(dist), 0);
    fill(begin(prevv), end(prevv), 0);
    fill(begin(preve), end(preve), 0);
  }
  using P = pair<Cost, int>;
  Cost res = 0;
  while (f > 0) {
    priority_queue<P, vector<P>, greater<P>> que;
    fill(begin(dist), end(dist), inf<Cost>());
    dist[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
      P p = que.top();
      que.pop();
      int v = p.second;
      if (dist[v] < p.first)
        continue;
      for (int i = 0; i < (int)g[v].size(); ++i) {
        const auto &e = g[v][i];
        if (e.cap <= 0)
          continue;
        if (dist[e.to] > dist[v] + e.cost + h[v] - h[e.to] /* + eps */) {
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          que.push(P(dist[e.to], e.to));
        }
      }
    }
    if (dist[t] == inf<Cost>())
      return -1;
    for (int i = 0; i < V; ++i) {
      h[i] += dist[i];
    }

    Flow d = f;
    for (int v = t; v != s; v = prevv[v]) {
      d = min(d, g[prevv[v]][preve[v]].cap);
    }
    f -= d;
    res += d * h[t];
    for (int v = t; v != s; v = prevv[v]) {
      auto &e = g[prevv[v]][preve[v]];
      e.cap -= d;
      g[v][e.rev].cap += d;
    }
  }
  return res;
}

struct Edge {
  using Flow = int;
  using Cost = int;
  int to, rev;
  Flow cap;
  Cost cost;
  Edge(int t, Flow f, int r, Cost c) : to(t), rev(r), cap(f), cost(c) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to, Edge::Flow cap, Edge::Cost cost) {
  g[from].emplace_back(to, cap, (int)g[to].size(), cost);
  g[to].emplace_back(from, 0, (int)g[from].size() - 1, -cost);
}
{% endhighlight %}

### Includes

- [util.hpp](../util)

[Back](../..)
