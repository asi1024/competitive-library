## recession.cpp

- [GitHub]({{ site.github.repository_url }}/bolb/master/cpp/include/graph/recession.cpp)

```cpp
int update(const Graph &g, vector<int> &res, int v) {
  for (auto e: g[v]) {
    if (res[e.to] == -1) {
      res[v] = 1;
      return 1;
    }
  }
  res[v] = -1;
  return 1e9;
}

template <typename T>
void recession(const Graph &g, vector<T> &res) {
  assert(g.size() == res.size());
  int n = g.size();
  vector<vector<int>> rg(n);
  for (int i = 0; i < n; ++i)
    for (auto e: g[i]) rg[e.to].push_back(i);
  vector<int> cnt(n);
  for (int i = 0; i < n; ++i) cnt[i] = g[i].size();
  queue<int> que;
  for (int i = 0; i < n; ++i)
    if (cnt[i] == 0) que.push(i);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    int c = update(g, res, v);
    for (int i: rg[v]) {
      if (cnt[i] <= 0) continue;
      cnt[i] -= c;
      if (cnt[i] <= 0) que.push(i);
    }
  }
}

// Verified : CodeFestival2015WF D (Dictionary for Shiritori Game)
/*
int main() {
  int N, M;
  cin >> N >> M;
  Graph<int> g(2 * N);
  for (int i = 0; i < M; ++i) {
    int p, q;
    cin >> p >> q;
    --p; --q;
    add_edge(g, p, q + N);
    add_edge(g, p + N, q);
  }
  vector<int> res(2 * N, 0);
  recession(g, res);
  if (res[0] == -1) cout << "Sothe" << endl;
  if (res[0] ==  0) cout << "Draw"  << endl;
  if (res[0] ==  1) cout << "Snuke" << endl;
  return 0;
}
*/
```

- [Back](https://{{ site.github.owner_name }}.github.io/competitive-library)
