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
