class BipartiteMatching {
  int V;
  vector<vector<int>> g;
  vector<int> match;
  vector<bool> used;
  bool dfs(int v) {
    used[v] = true;
    for (int u: g[v]) {
      int w = match[u];
      if (w < 0 || (!used[w] && dfs(w))) {
        match[v] = u; match[u] = v;
        return true;
      }
    }
    return false;
  }
public:
  BipartiteMatching (int v) : V(v), g(v), match(v), used(v) {}
  void add_edge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int maximum_matching(void) {
    int res = 0;
    fill (ALL(match), -1);
    REP(v, V) {
      if (match[v] < 0) {
        fill (ALL(used), 0);
        if (dfs(v)) res++;
      }
    }
    return res;
  }
};
