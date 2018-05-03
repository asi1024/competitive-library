## retrograde

{% highlight cpp %}
vector<Game> retrograde(const vector< vector< Edge >> &g);{% endhighlight %}

## add_edge

{% highlight cpp %}
void add_edge(Graph &g, int from, int to);{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/retrograde.cpp)

{% highlight cpp %}
enum Game { WIN, LOSE, DRAW };

template<typename Edge>
vector<Game> retrograde(const vector<vector<Edge>> &g) {
  const int n = g.size();
  vector<vector<int>> rg(n);
  for (int i = 0; i < n; ++i) {
    for (auto e: g[i]) rg[e.to].push_back(i);
  }
  vector<int> cnt(n);
  for (int i = 0; i < n; ++i) cnt[i] = g[i].size();
  queue<int> que;
  vector<Game> res(n, DRAW);
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 0) {
      res[i] = LOSE;
      que.emplace(i);
    }
  }
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    if (res[v] == WIN) {
      for (Edge e: rg[v]) {
        if (res[e.to] == WIN) continue;
        cnt[e.to]--;
        if (cnt[e.to] == 0) {
          res[e.to] = LOSE;
          que.emplace(e.to);
        }
      }
    }
    else {
      for (Edge e: rg[v]) {
        if (res[e.to] != WIN) {
          res[e.to] = WIN;
          que.emplace(e.to);
        }
      }
    }
  }
  return res;
}

struct Edge {
  int to;
  Edge(int t) : to(t) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to) {
  g[from].emplace_back(to);
}
{% endhighlight %}

[Back](../..)
