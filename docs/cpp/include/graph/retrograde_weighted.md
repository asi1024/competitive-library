{% include mathjax.html %}

## retrograde

{% highlight cpp %}
std::vector<Game_with_Cost<Cost> > retrograde(const graph_t< edge_t > &g);
{% endhighlight %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
Game_with_Cost();
Game_with_Cost(Game w, Cost c);
{% endhighlight %}


---------------------------------------

{% include mathjax.html %}

### Memo

- 二人ゲーム．グラフ上を交互に移動していき，移動できなくなった方が負け．
- 勝者はパスのコストがなるべく小さくなるように，敗者は長くなるように選ぶ．
- 各ノードから始めたときの先手の勝敗とコストを返す．

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/retrograde_weighted.cpp)

{% highlight cpp %}
#include "definition.hpp"
#include "retrograde.hpp"

template <typename Cost> struct Game_with_Cost {
  Game win;
  Cost cost;
  Game_with_Cost() : win(DRAW), cost(inf<Cost>()) { ; }
  Game_with_Cost(Game w, Cost c) : win(w), cost(c) { ; }
};

template <typename edge_t, typename Cost = typename edge_t::cost_type>
std::vector<Game_with_Cost<Cost>> retrograde(const graph_t<edge_t> &g) {
  using P = std::pair<Cost, int>;
  const int n = g.size();
  std::vector<std::vector<P>> rg(n);
  for (int i = 0; i < n; ++i) {
    for (const auto &e : g[i]) rg[e.to].emplace_back(e.cost, i);
  }
  std::vector<int> cnt(n);
  for (int i = 0; i < n; ++i) cnt[i] = g[i].size();
  std::priority_queue<P, std::vector<P>, std::greater<P>> que;
  std::vector<Game_with_Cost<Cost>> res(n);
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 0) {
      res[i] = Game_with_Cost<Cost>(LOSE, 0);
      que.emplace(Cost(0), i);
    }
  }
  while (!que.empty()) {
    Cost cost;
    int v;
    std::tie(cost, v) = que.top();
    que.pop();
    if (res[v].win == WIN) {
      if (res[v].cost != cost) continue;
      for (const P &e : rg[v]) {
        if (res[e.second].win == WIN) continue;
        cnt[e.second]--;
        if (cnt[e.second] == 0) {
          res[e.second].win = LOSE;
          que.emplace(Cost(0), e.second);
        }
      }
    }
    else {
      for (const edge_t &e : g[v]) {
        cost = std::max(cost, res[e.to].cost + e.cost);
      }
      res[v].cost = cost;
      for (const P &e : rg[v]) {
        res[e.second].win = WIN;
        if (cost + e.first < res[e.second].cost) {
          res[e.second].cost = cost + e.first;
          que.emplace(res[e.second].cost, e.second);
        }
      }
    }
  }
  return res;
}
{% endhighlight %}

### Includes

- [definition.hpp](definition)
- [retrograde.hpp](retrograde)

[Back](../..)
