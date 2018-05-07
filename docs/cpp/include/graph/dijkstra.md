{% include mathjax.html %}

## dijkstra

{% highlight cpp %}
vector<Cost> dijkstra(const vector< vector< Edge >> &g, int s, Cost zero=0);
{% endhighlight %}

- 負辺のない重み付きグラフの単一始点全点間最短距離を求める．

### Parameters

|:--:|:--|
|`g`|負辺のない重み付きグラフ|
|`s`|始点の頂点番号|
|`zero`|型 Cost のゼロ値|

#### Type requirements

- Graph は vector<vector< dge >> 型である．
- int edge::to が定義されている
- typename edge::Cost が定義されていて，Cost の全順序と加算が定義されている．

### Return value

- 始点から各頂点までの距離が入った型 Cost の列

### Notes

- 入力グラフに不辺があってはならない

### Time Complexity

- $O(E \log V)$

---------------------------------------

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

{% include mathjax.html %}

### Usage

{% highlight cpp %}
vector<Cost> dijkstra(const vector<vector<Edge>> &g, int s, Cost zero = 0);
{% endhighlight %}

負辺のない重み付きグラフの単一始点全点間最短距離を求める．

### Parameters
- `g` : 負辺のない重み付きグラフ
- `s` : 始点の頂点番号
- `zero` : 型 Cost のゼロ値

### Type requirements
- `Cost` 同士の加算と比較が定義されている必要がある．

### Return value
各頂点までの距離が入った型 `Cost` の列

### Exceptions
(none)

### Time Complexity
- $O(E \log V)$

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/dijkstra.cpp)

{% highlight cpp %}
#include "../util.hpp"

template <typename Edge, typename Cost = typename Edge::Cost>
vector<Cost> dijkstra(const vector<vector<Edge>> &g, int s, Cost zero = 0) {
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

### Includes

- [util.hpp](../util)

[Back](../..)
