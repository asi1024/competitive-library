{% include mathjax.html %}

## spfa

{% highlight cpp %}
pair<bool,vector<Cost> > spfa(const vector< vector< Edge >> &g, int s, Cost zero=0);
{% endhighlight %}

## add_edge

{% highlight cpp %}
void add_edge(Graph &g, int from, int to, Edge::Cost cost);
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

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/spfa.cpp)

{% highlight cpp %}
template <typename Edge, typename Cost = typename Edge::Cost>
pair<bool,vector<Cost>> spfa(const vector<vector<Edge>> &g, int s, Cost zero = 0) {
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
  int to;
  Cost cost;
  Edge(int t, Cost c) : to(t), cost(c) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to, Edge::Cost cost) {
  g[from].emplace_back(to, cost);
}
{% endhighlight %}

{% include mathjax.html %}

### Usage

{% highlight cpp %}
pair<bool,vector<Cost>> spfa(const vector<vector<Edge>> &g, int s, Cost zero = 0);
{% endhighlight %}

重み付きグラフの単一始点全点間最短距離を求める．

### Parameters
- `g` : 負辺のない重み付きグラフ
- `s` : 始点の頂点番号
- `zero` : 型 Cost のゼロ値

### Type requirements
- `Cost` 同士の加算と比較が定義されている必要がある．

### Return value
- `s` から到達可能な負閉路が存在しない場合
  - `result.first` : `true`
  - `result.second` : 各頂点までの距離が入った型 `Cost` の列
- `s` から到達可能な負閉路が存在する場合
  - `result.first` : `false`
  - `result.second` : 未定義

### Exceptions
(none)

### Time Complexity
- $O(EV)$

[Back](../..)
