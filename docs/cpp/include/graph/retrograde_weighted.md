{% include mathjax.html %}

## retrograde

{% highlight cpp %}
vector<Game_with_Cost<Cost> > retrograde(const vector< vector< Edge >> &g);
{% endhighlight %}

## add_edge

{% highlight cpp %}
void add_edge(Graph &g, int from, int to, Edge::Cost cost);
{% endhighlight %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
Game_with_Cost();
Game_with_Cost(Game w, T c);
{% endhighlight %}


---------------------------------------

## Member functions

### [1] (constructor)
{% highlight cpp %}
Edge(int s, int t);
Edge(int t);
Edge(int t, Flow f, int r);
Edge(int t, Flow f, int r, Cost c);
Edge(int t);
Edge(int t, Cost c);
Edge(int, int t);
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
#include "../util.hpp"

enum Game { WIN, LOSE, DRAW };

template <typename T> struct Game_with_Cost {
  Game win;
  T cost;
  Game_with_Cost() : win(DRAW), cost(inf<T>()) { ; }
  Game_with_Cost(Game w, T c) : win(w), cost(c) { ; }
};

template <typename Edge, typename Cost = typename Edge::Cost>
vector<Game_with_Cost<Cost>> retrograde(const vector<vector<Edge>> &g) {
  const int n = g.size();
  vector<vector<Edge>> rg(n);
  for (int i = 0; i < n; ++i) {
    for (auto e : g[i])
      rg[e.to].push_back(Edge(i, e.cost));
  }
  vector<int> cnt(n);
  for (int i = 0; i < n; ++i)
    cnt[i] = g[i].size();
  using P = pair<Cost, int>;
  priority_queue<P, vector<P>, greater<P>> que;
  vector<Game_with_Cost<Cost>> res(n);
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 0) {
      res[i] = Game_with_Cost<Cost>(LOSE, 0);
      que.emplace(Cost(0), i);
    }
  }
  while (!que.empty()) {
    Cost cost;
    int v;
    tie(cost, v) = que.top();
    que.pop();
    if (res[v].win == WIN) {
      if (res[v].cost != cost)
        continue;
      for (Edge e : rg[v]) {
        if (res[e.to].win == WIN)
          continue;
        cnt[e.to]--;
        if (cnt[e.to] == 0) {
          res[e.to].win = LOSE;
          que.emplace(Cost(0), e.to);
        }
      }
    } else {
      for (Edge e : g[v]) {
        cost = max(cost, res[e.to].cost + e.cost);
      }
      res[v].cost = cost;
      for (Edge e : rg[v]) {
        res[e.to].win = WIN;
        if (cost + e.cost < res[e.to].cost) {
          res[e.to].cost = cost + e.cost;
          que.emplace(res[e.to].cost, e.to);
        }
      }
    }
  }
  return res;
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
