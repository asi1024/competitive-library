## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/heavy_light_decomposition.cpp)

{% highlight cpp %}
template <typename DataStructure>
struct HeavyLightDecomposition {
  using T = typename DataStructure::value_type;
  using Update = typename DataStructure::update_type;
  using Monoid = typename DataStructure::monoid_type;
  struct Chain {
    int depth;
    pair<int,int> parent;        // chain number, index
    vector<pair<int,int>> child; // child chain number, parent index
    vector<int> mapfrom;
    DataStructure up, down;
    Chain (int n, const T &init) : up(n, init), down(n, init) {;}
  };

  vector<Chain> chains;
  vector<pair<int,int>> mapto; // raw index -> chain number & index
  vector<vector<int>> mapfrom; // chain number & index -> raw index

  int root() const { return mapfrom[0][0]; }

  template<typename Graph>
  HeavyLightDecomposition(const Graph &g, const T &init = Monoid::id()) {
    const int n = g.size();
    mapto = vector<pair<int,int>>(n, make_pair(-1, -1));
    mapfrom.clear();
    vector<int> size(n, 0);
    int start = -1;
    for (int i = 0; i < n; i++) {
      if (g[i].size() <= 1) { start = i; break; }
    }
    assert(start != -1);
    size_check_bfs(g, start, size);
    decomposition(g, start, start, 0, 0, 0, size, init);
  }

  void update(int i, const Update &val) {
    pair<int,int> chain_id = mapto[i];
    const int n = chains[chain_id.first].mapfrom.size();
    chains[chain_id.first].up.update(n - i - 1, val);
    chains[chain_id.first].down.update(i, val);
  }

  void update(int s, int t, const Update &update) {
    pair<int,int> chain_s = mapto[s], chain_t = mapto[t];
    while (chain_s.first != chain_t.first) {
      if (chains[chain_s.first].depth > chains[chain_t.first].depth) {
        const int num = chain_s.second + 1;
        const int n = chains[chain_s.first].mapfrom.size();
        chains[chain_s.first].up.update(n - num, n, update);
        chains[chain_s.first].down.update(0, num, update);
        chain_s = chains[chain_s.first].parent;
      }
      else {
        const int num = chain_t.second + 1;
        const int n = chains[chain_t.first].mapfrom.size();
        chains[chain_t.first].up.update(n - num, n, update);
        chains[chain_t.first].down.update(0, num, update);
        chain_t = chains[chain_t.first].parent;
      }
    }
    const int n = chains[chain_s.first].mapfrom.size();
    const int l = min(chain_s.second, chain_t.second);
    const int r = max(chain_s.second, chain_t.second);
    chains[chain_s.first].up.update(n - r - 1, n - l, update);
    chains[chain_s.first].down.update(l, r + 1, update);
  }

  T query(int s, int t) {
    T res1 = Monoid::id(), res2 = Monoid::id();
    pair<int,int> chain_s = mapto[s], chain_t = mapto[t];
    while (chain_s.first != chain_t.first) {
      if (chains[chain_s.first].depth > chains[chain_t.first].depth) {
        const int num = chain_s.second + 1;
        const int n = chains[chain_s.first].mapfrom.size();
        T val = chains[chain_s.first].up.query(n - num, n);
        res1 = Monoid::op(res1, val);
        chain_s = chains[chain_s.first].parent;
      }
      else {
        const int num = chain_t.second + 1;
        T val = chains[chain_t.first].down.query(0, num);
        res2 = Monoid::op(val, res2);
        chain_t = chains[chain_t.first].parent;
      }
    }
    const int n = chains[chain_s.first].mapfrom.size();
    const int l = chain_s.second;
    const int r = chain_t.second;
    T val = l > r ?
      chains[chain_s.first].up.query(n - l - 1, n - r) :
      chains[chain_s.first].down.query(l, r + 1);
    return Monoid::op(Monoid::op(res1, val), res2);
  }

  int depth(int t) const { return chains[mapto[t].first].depth; }

private:
  template<typename Graph>
  int decomposition(Graph &g, int from, int parent, int depth,
                    int pnumber, int pindex,
                    const vector<int> &size, const T &init) {
    vector<int> seq;
    bfs(g, from, parent, seq, size);
    const int c = chains.size();
    chains.push_back(Chain(int(seq.size()), init));
    chains[c].depth = depth;
    chains[c].parent = make_pair(pnumber, pindex);
    for (int i = 0; i < int(seq.size()); i++) {
      mapto[seq[i]] = make_pair(c, i);
      chains[c].mapfrom.push_back(seq[i]);
    }
    mapfrom.push_back(chains[c].mapfrom);
    for (int i = 0; i < int(seq.size()); i++) {
      for (auto e: g[seq[i]]) {
        if (mapto[e.to].first != -1) continue;
        int nc = decomposition(g, e.to, seq[i], depth + 1, c, i, size, init);
        chains[c].child.push_back(make_pair(nc, i));
      }
    }
    return c;
  }
  template<typename Graph>
  void size_check_bfs(const Graph &g, int start, vector<int> &size) {
    const int n = g.size();
    queue<pair<int,int>> que;
    que.push(make_pair(start, start));
    int cnt = 0;
    vector<int> order(n, -1);
    while (!que.empty()) {
      int from, parent; tie(from, parent) = que.front(); que.pop();
      order[cnt++] = from;
      for (auto e: g[from]) {
        if (e.to == parent) continue;
        que.push(make_pair(e.to, from));
      }
    }
    assert(cnt == n);
    reverse(begin(order), end(order));
    for (int i = 0; i < n; i++) {
      int from = order[i];
      size[from] = 1;
      for (auto e: g[from]) size[from] += size[e.to];
    }
  }
  template<typename Graph>
  void bfs(const Graph &g, int from, int parent,
           vector<int> &seq, const vector<int> &size) {
    for (;;) {
      seq.push_back(from);
      int best = -1, next = -1;
      for (auto e: g[from]) {
        if (e.to == parent) continue;
        if (best < size[e.to]) { best = size[e.to]; next = e.to; }
      }
      if (next == -1) break;
      parent = from; from = next;
    }
  }
};
{% endhighlight %}

[Back](../..)
