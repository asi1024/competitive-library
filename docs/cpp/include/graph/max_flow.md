{% include mathjax.html %}

## augment

{% highlight cpp %}
Flow augment(vector< vector< Edge >> &g, vector< int > &d, vector< int > &iter, int v, int t, const Flow &f);
{% endhighlight %}

## max_flow

{% highlight cpp %}
Flow max_flow(vector< vector< Edge >> &g, int s, int t, Flow zero=0);
{% endhighlight %}

## add_edge

{% highlight cpp %}
void add_edge(Graph &g, int from, int to, Edge::Flow cap);
{% endhighlight %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
Edge(int s, int t);
Edge(int t, Cost c);
Edge(int t, Cost c);
Edge(int t);
Edge(int t, Flow f, int r);
Edge(int t, Flow f, int r, Cost c);
Edge(int t);
Edge(int t, Cost c);
Edge(int t);
Edge(int t, Cost c);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/max_flow.cpp)

{% highlight cpp %}
#include "../util.hpp"

template <typename Edge, typename Flow = typename Edge::Flow>
Flow augment(vector<vector<Edge>> &g, vector<int> &d, vector<int> &iter,
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

template <typename Edge, typename Flow = typename Edge::Flow>
Flow max_flow(vector<vector<Edge>> &g, int s, int t, Flow zero = 0) {
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
  int to, rev;
  Flow cap;
  Edge(int t, Flow f, int r) : to(t), rev(r), cap(f) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to, Edge::Flow cap) {
  g[from].emplace_back(to, cap, (int)g[to].size());
  g[to].emplace_back(from, 0, (int)g[from].size() - 1);
}
{% endhighlight %}

### Includes

- [util.hpp](../util)

[Back](../..)
