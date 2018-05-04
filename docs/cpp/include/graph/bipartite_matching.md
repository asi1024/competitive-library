## BipartiteMatching

### Member functions

- (constructor)
- add_edge
- maximum_matching

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/bipartite_matching.cpp)

{% highlight cpp %}
class BipartiteMatching {
  int size;
  vector<vector<int>> g;
  vector<int> match;
  vector<bool> used;
  bool dfs(int v) {
    used[v] = true;
    for (int u: g[v]) {
      int w = match[u];
      if (w < 0 || (!used[w] && dfs(w))) {
        match[v] = u;
        match[u] = v;
        return true;
      }
    }
    return false;
  }
public:
  BipartiteMatching(int v) : size(v), g(v), match(v), used(v) {}
  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int maximum_matching(void) {
    int res = 0;
    fill(begin(match), end(match), -1);
    for (int v = 0; v < size; ++v) {
      if (match[v] >= 0) continue;
      fill(begin(used), end(used), 0);
      if (dfs(v)) ++res;
    }
    return res;
  }
};
{% endhighlight %}

[Back](../..)
