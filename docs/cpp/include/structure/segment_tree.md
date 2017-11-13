## segment_tree.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/segment_tree.cpp)

{% highlight cpp %}
template <class Monoid>
class SegmentTree {
  using T = typename Monoid::type;
  const int sz, n;
  std::vector<T> data;
  int expand(int n) const { return n == 1 ? n : expand((n + 1) / 2) * 2; }
public:
  SegmentTree(const std::vector<T> &init) :
    sz(init.size()), n(expand(sz)), data(n * 2, Monoid::id()) {
    std::copy(begin(init), end(init), begin(data) + n);
    for (int i = n - 1; i >= 0; --i) {
      data[i] = Monoid::op(data[i * 2 + 0], data[i * 2 + 1]);
    }
  }
  SegmentTree(const int n, const T &init = Monoid::id()) :
    SegmentTree(std::vector<T>(n, init)) {}
  int size() const { return sz; }
  void update(int p, T val) {
    assert (0 <= p && p < sz); // assertion
    data[p += n] = val;
    while (p /= 2) data[p] = Monoid::op(data[p * 2], data[p * 2 + 1]);
  }
  T query(int l, int r) const {
    assert (0 <= l && l <= r && r <= sz); // assertion
    l += n; r += n;
    T res1 = Monoid::id(), res2 = Monoid::id();
    while (l != r) {
      if (l % 2) res1 = Monoid::op(res1, data[l++]);
      if (r % 2) res2 = Monoid::op(data[--r], res2);
      l /= 2; r /= 2;
    }
    return Monoid::op(res1, res2);
  }
};

struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(const type &l, const type &r) { return min(l, r); }
};
{% endhighlight %}

{% include mathjax.html %}

### Usage

{% highlight cpp %}
(1) SegmentTree<Monoid>(int n);
(2) SegmentTree<Monoid>(int n, const Monoid::type& init);
(3) SegmentTree<Monoid>(const std::vector<Monid::type>& init);
(4) int size() const;
(5) void update(int p, const Monoid::type& val);
(6) Monoid::type query(int l, int r) const;
{% endhighlight %}

- (1): 長さ $n$ の Monoid::type の列を初期値 Monoid::id() で作る．
  - ただし，Monoid::id() はモノイドの単位元を返す関数．
- (2): 長さ $n$ の Monoid::type の列を初期値 init で作る．
- (3): 列 init を作る．
- (4): 列の長さを返す．
- (5): 列の $p$ 番目の値を val に変更する．
- (6): $a_l \cdot a_{l + 1} \cdot \ldots \cdot a_{r - 1}$ の値を返す．
  - ただし，モノイドの二項演算 $\cdot$ は Monoid::op で定義する．

### Time Complexity
- (1): $O(n)$
- (2): $O(n)$
- (3): $O(n)$
- (4): $O(1)$
- (5): $O(\log(n))$
- (6): $O(\log(n))$

[Back](../../..)
