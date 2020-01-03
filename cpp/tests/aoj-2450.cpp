#include "../include/structure/heavy_light_decomposition.cpp"
#include "../include/structure/segment_tree_lazy.cpp"
#include "../include/structure/semi_group.hpp"
#include "../include/template/typedef.hpp"

using namespace std;

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
  using value_type = Data;
  static value_type id() { return Data(0, 0, 0, 0, -1e18, 0); }
  static value_type op(const value_type &l, const value_type &r) {
    return Data(max({ l.res, r.res, l.right + r.left }),
                max(l.left, l.sum + r.left), max(r.right, r.sum + l.right),
                l.sum + r.sum, max(l.max, r.max), l.cnt + r.cnt);
  }
};

struct Struct {
  using Monoid = RangeMinSegment;
  using Update = LeftHandSide<ll>;
  using value_type = typename Monoid::value_type;
  using update_type = typename Update::value_type;
  static value_type evaluate(const update_type &update, const value_type &val) {
    ll sum = update * val.cnt;
    if (update < 0)
      return value_type(0, 0, 0, sum, update, val.cnt);
    else
      return value_type(sum, sum, sum, sum, update, val.cnt);
  }
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
  HeavyLightDecomposition<SegmentTreeLazy<Struct>> HLD(g, Data());
  for (int i = 0; i < n; i++) HLD.update(i, i, w[i]);
  for (int i = 0; i < q; i++) {
    int com, s, t, c;
    scanf("%d%d%d%d", &com, &s, &t, &c);
    --s;
    --t;
    if (com == 1) {
      HLD.update(s, t, c);
    }
    else {
      Data val = HLD.query(s, t);
      ll res = (val.max >= 0 ? val.res : val.max);
      printf("%lld\n", res);
    }
  }
  return 0;
}
