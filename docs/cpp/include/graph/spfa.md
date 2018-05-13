{% include mathjax.html %}

## spfa

{% highlight cpp %}
std::pair<bool,std::vector<cost_type> > spfa(const graph_t< edge_t > &g, int s);
{% endhighlight %}

- 重み付きグラフの単一始点全点間最短距離を求める．

### Parameters

|:--:|:--|
|`g`|重み付きグラフ|
|`s`|始点の頂点番号|

#### Type requirements

- edge_t

### Return value

- s から到達可能な負閉路が存在しない場合: (true, 各頂点までの距離が入った型
- s から到達可能な負閉路が存在する場合: (false, 未定義)

### Time Complexity

- $O(EV)$

---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/spfa.cpp)

{% highlight cpp %}
#include "../template/const_value.hpp"
#include "definition.hpp"

template <typename edge_t, typename cost_type = typename edge_t::cost_type>
std::pair<bool,std::vector<cost_type>> spfa(const graph_t<edge_t> &g, int s) {
  const int n = g.size();
  std::vector<cost_type> d(n, inf<cost_type>); d[s] = zero<cost_type>;
  std::vector<int> updated(n, 0);
  std::vector<bool> inque(n, false);
  std::queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int from = que.front();
    que.pop();
    inque[from] = false;
    ++updated[from];
    if (updated[from] == n + 1) return {false, d}; // negative cycle
    for (const auto &e: g[from]) {
      cost_type cost = d[from] + e.cost;
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
{% endhighlight %}

### Includes

- [const_value.hpp](../template/const_value)
- [definition.hpp](definition)

[Back](../..)
