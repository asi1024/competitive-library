## segment_tree.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/segment_tree.cpp)

{% highlight cpp %}
template <class Monoid>
class SegmentTree {
  using T = typename Monoid::type;
  const int size_, n;
  std::vector<T> data;
  int expand(int m) const { return m == 1 ? m : expand((m + 1) / 2) * 2; }
public:
  SegmentTree(const std::vector<T> &vec) :
    size_(vec.size()), n(expand(size_)), data(n * 2, Monoid::id()) {
    std::copy(begin(vec), end(vec), begin(data) + n);
    for (int i = n - 1; i >= 0; --i) {
      data[i] = Monoid::op(data[i * 2 + 0], data[i * 2 + 1]);
    }
  }
  SegmentTree(const int count, const T &value = Monoid::id()) :
    SegmentTree(std::vector<T>(count, value)) {}
  int size() const { return size_; }
  void update(int pos, const T &value) {
    assert (0 <= pos && pos < size_); // assertion
    data[pos += n] = value;
    while (pos /= 2) {
      data[pos] = Monoid::op(data[pos * 2], data[pos * 2 + 1]);
    }
  }
  T query(int l, int r) const {
    assert (0 <= l && l <= r && r <= size_); // assertion
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

[モノイド](https://ja.wikipedia.org/wiki/モノイド)をクラスで定義して，以下のようにテンプレート引数を用いて渡す．

{% highlight cpp %}
class Monoid
(1) typename type;
(2) static type id();
(3) static type op(const type& l, const type& r);
{% endhighlight %}

- (1): Monoid のデータ型
- (2): Monoid の単位元を返す定数関数
- (3): Monoid の二項演算．この演算は結合則を満たす必要がある．

{% highlight cpp %}
(1) SegmentTree(const vector<Monoid::type>& vec);
(2) SegmentTree(int count, const Monoid::type& value = Monoid::id());
(3) int size() const;
(4) void update(int pos, const Monoid::type& value);
(5) Monoid::type query(int l, int r) const;
{% endhighlight %}

- (1): vector<T> 型の列 vec を表現するセグメント木を作る．
- (2): 長さ count のセグメント木を作り，全ての要素を value で初期化する．
- (3): セグメント木のサイズを返す．
- (4): pos 番目の要素を value に更新する．
  - pos はセグメント木のサイズ未満の非負整数である必要がある．
  - その範囲を超えた場合は例外を送出する．
- (5): セグメント木の区間 [l, r) を演算 Monoid::op ($\cdot$) で畳み込んだ値を返す．
  - すなわち，$a_l \cdot a_{l+1} \cdot \ldots \cdot a_{r-1}$ を返す．
  - $l = r$ の場合は Monoid::id() を返す．

### Time Complexity
Monoid::op にかかる時間を定数時間とすると，
- (1): $O(n)$
- (2): $O(n)$
- (3): $O(1)$
- (4): $O(\log(n))$
- (5): $O(\log(n))$

[Back](../..)
