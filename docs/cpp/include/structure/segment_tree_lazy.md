## segment_tree_lazy.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/segment_tree_lazy.cpp)

{% highlight cpp %}
template<typename Update>
class SegmentTreeLazy {
  const int n;
  using type = typename Update::type;
  using Monoid = typename Update::Monoid;
  vector<type> data;
  vector<Update> lazy;
  vector<bool> flag;
  void lazyset(int node, const Update &f) {
    if (node < n) {
      if (flag[node]) { lazy[node] = f(lazy[node]); }
      else { lazy[node] = f; flag[node] = true; }
    }
    data[node] = f(data[node]);
  }
  void evaluate(int node) {
    if (!flag[node]) return;
    flag[node] = false;
    lazyset(node * 2 + 0, lazy[node]);
    lazyset(node * 2 + 1, lazy[node]);
  }
  void update_sub(int l, int r, int node, int lb, int ub, const Update &f) {
    if (ub <= l || r <= lb) { return; }
    if (l <= lb && ub <= r) { lazyset(node, f); return; }
    evaluate(node);
    const int mid = (lb + ub) / 2;
    update_sub(l, r, node * 2 + 0, lb, mid, f);
    update_sub(l, r, node * 2 + 1, mid, ub, f);
    data[node] = Monoid::op(data[node * 2 + 0], data[node * 2 + 1]);
  }
  type query_sub(int l, int r, int node, int lb, int ub) {
    if (ub <= l || r <= lb) return Monoid::id();
    if (l <= lb && ub <= r) { return data[node]; }
    evaluate(node);
    const int mid = (lb + ub) / 2;
    type lval = query_sub(l, r, node * 2 + 0, lb, mid);
    type rval = query_sub(l, r, node * 2 + 1, mid, ub);
    return Monoid::op(lval, rval);
  }
  int expand(int m) const { return m == 1 ? m : expand((m + 1) / 2) * 2; }
public:
  SegmentTreeLazy(int count) :
    n(expand(count)), data(n * 2, Monoid::id()), lazy(n), flag(n, false) {;}
  void update(int l, int r, const Update &f) { update_sub(l, r, 1, 0, n, f); }
  type query(int l, int r) { return query_sub(l, r, 1, 0, n); }
};

struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(const type &l, const type &r) { return min(l, r); }
};

struct RangeUpdate {
  using Monoid = RMQ;
  using type = RMQ::type;
  int val;
  RangeUpdate() : val(0) {;}
  RangeUpdate(int v) : val(v) {;}
  type operator()(const type &) const { return val; }
  RangeUpdate operator()(const RangeUpdate &) const { return *this; }
};
{% endhighlight %}

[Back](../..)
