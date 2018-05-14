// Verified: Codeforces 804D

#include "../util.hpp"
#include "../structure/unionfind.cpp"

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using Graph = vector<vector<int>>;

struct Algebra {
  using type = int;
  static type id() { return 0; }
  static type op1(const type &v) { return v + 1; }
  static type op2(const type &l, const type &r) { return max(l, r); }
};

template<typename ComMonoid>
struct TreeDP {
  using T = typename ComMonoid::type;
  const int n;
  const Graph g;
  vector<vector<bool>> visitedl, visitedr;
  vector<vector<T>> memol, memor;
  T dfsl(int v, int pos) {
    if (pos == 0) return 0;
    if (visitedl[v][pos]) return memol[v][pos];
    visitedl[v][pos] = true;
    const T l = dfsl(v, pos - 1);
    const T r = dfsv(g[v][pos-1], v);
    return memol[v][pos] = ComMonoid::op2(l, r);
  }
  T dfsr(int v, int pos) {
    if (pos == int(g[v].size())) return 0;
    if (visitedr[v][pos]) return memor[v][pos];
    visitedr[v][pos] = true;
    const T l = dfsv(g[v][pos], v);
    const T r = dfsr(v, pos + 1);
    return memor[v][pos] = ComMonoid::op2(l, r);
  }
  T dfsv(int v, int p) {
    int pos = lower_bound(ALL(g[v]), p) - begin(g[v]);
    const T l = dfsl(v, pos);
    const T r = dfsr(v, pos + 1);
    return ComMonoid::op1(ComMonoid::op2(l, r));
  }
  Graph init(Graph g) {
    for (int i = 0; i < int(g.size()); ++i)
      sort(begin(g[i]), end(g[i]));
    return g;
  }
  TreeDP(const Graph &g) :
    n(g.size()), g(init(g)),
    visitedl(n + 1), visitedr(n + 1), memol(n + 1), memor(n + 1) {
    for (int i = 0; i < n; ++i) {
      visitedl[i].assign(g[i].size() + 1, false);
      visitedr[i].assign(g[i].size() + 1, false);
      memol[i].resize(g[i].size() + 1);
      memor[i].resize(g[i].size() + 1);
    }
  }
  T query(int v) { return dfsr(v, 0); }
};

/* ---------------------------------- Main ---------------------------------- */

vector<int> cc[100010];
vector<int> cnt[100010];
vector<ll> sum[100010];
vector<ll> sump[100010];
int maxd[100010];

int main() {
  cout << setprecision(12) << fixed;
  locale loc(locale(), new yes_no);
  cout << boolalpha;
  cout.imbue(loc);

  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  Graph g(n);
  UnionFind uf(n);
  vector<int> is_tree(n, 1);
  REP(i,m) {
    int s, t;
    scanf("%d%d", &s, &t);
    --s; --t;
    g[s].push_back(t);
    g[t].push_back(s);
    bool tr = is_tree[uf.root(s)] && is_tree[uf.root(t)];
    if (!uf.unite(s, t) || !tr) is_tree[uf.root(s)] = 0;
  }
  REP(i,n) sort(ALL(g[i]));
  REP(i,n) cc[uf.root(i)].push_back(i);
  TreeDP<Algebra> dp(g);
  REP(i,n) {
    if (cc[i].empty()) continue;
    const int m = cc[i].size();
    cnt[i].assign(m, 0);
    sum[i].assign(m + 1, 0);
    sump[i].assign(m + 1, 0);
    for (int j: cc[i]) {
      int d = dp.query(j);
      chmax(maxd[i], d);
      ++cnt[i][d];
    }
    REP(j,m) {
      sum[i][j+1] = sum[i][j] + cnt[i][j];
      sump[i][j+1] = sump[i][j] + cnt[i][j] * j;
    }
  }
  map<pair<int,int>,ld> memoize;
  REP(i,q) {
    int s, t;
    scanf("%d%d", &s, &t);
    --s; --t;
    if (uf.root(s) == uf.root(t) ||
        !is_tree[uf.root(s)] || !is_tree[uf.root(t)]) {
      cout << -1 << endl;
    }
    else {
      s = uf.root(s); t = uf.root(t);
      if (cc[s].size() > cc[t].size()) swap(s, t);
      if (memoize.count(make_pair(s, t))) {
        cout << memoize[make_pair(s, t)] << endl;
        continue;
      }
      int least = max(maxd[s], maxd[t]);
      ll res = 0;
      REP(i,cc[s].size()) {
        int p = least - i - 1;
        if (p < 0) {
          res += ((i + 1) * sum[t].back() + sump[t].back()) * cnt[s][i];
        }
        else if (p > int(cc[t].size())) {
          res += (least * sum[t].back()) * cnt[s][i];
        }
        else {
          res += (least * sum[t][p] +
                  (i + 1) * (sum[t].back() - sum[t][p]) +
                  sump[t].back() - sump[t][p]) * cnt[s][i];
        }
      }
      ld ans = memoize[make_pair(s, t)] = ld(res) / cc[s].size() / cc[t].size();
      cout << ans << endl;
    }
  }
  return 0;
}
