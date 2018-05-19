#include "../include/structure/heavy_light_decomposition.cpp"
#include "../include/structure/segment_tree_lazy.cpp"

struct Edge {
  int to;
  Edge(int t) : to(t) { ; }
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int s, int t) {
  g[s].push_back(Edge(t));
  g[t].push_back(Edge(s));
}

struct Data {
  ll res, left, right, sum, max, cnt;
  Data(ll re, ll l, ll r, ll s, ll m, ll c) :
    res(re), left(l), right(r), sum(s), max(m), cnt(c) {
    ;
  }
  Data() : res(0), left(0), right(0), sum(0), max(0), cnt(1) { ; }
};

struct RangeMinSegment {
  using type = Data;
  static type id() { return Data(0, 0, 0, 0, -1e18, 0); }
  static type op(const type &l, const type &r) {
    return Data(max({ l.res, r.res, l.right + r.left }),
                max(l.left, l.sum + r.left), max(r.right, r.sum + l.right),
                l.sum + r.sum, max(l.max, r.max), l.cnt + r.cnt);
  }
};

struct Update {
  using Monoid = RangeMinSegment;
  using type = typename Monoid::type;
  ll update;
  Update() : update(0) { ; }
  Update(ll v) : update(v) { ; }
  type operator()(const type &val) const {
    ll sum = update * val.cnt;
    if (update < 0)
      return type(0, 0, 0, sum, update, val.cnt);
    else
      return type(sum, sum, sum, sum, update, val.cnt);
  }
  Update operator()(const Update &) const { return *this; }
};

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  vector<ll> w(n);
  for (int i = 0; i < n; i++) scanf("%lld", &w[i]);
  Graph g(n);
  for (int i = 0; i < n - 1; i++) {
    int s, t;
    scanf("%d%d", &s, &t);
    --s;
    --t;
    add_edge(g, s, t);
  }
  HeavyLightDecomposition<SegmentTreeLazy<Update>> HLD(g, Data());
  for (int i = 0; i < n; i++) HLD.update(i, i, Update(w[i]));
  for (int i = 0; i < q; i++) {
    int com, s, t, c;
    scanf("%d%d%d%d", &com, &s, &t, &c);
    --s;
    --t;
    if (com == 1) {
      HLD.update(s, t, Update(c));
    }
    else {
      Data val = HLD.query(s, t);
      ll res = (val.max >= 0 ? val.res : val.max);
      printf("%lld\n", res);
    }
  }
  return 0;
}
