

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/fenwick_tree.cpp)

{% highlight cpp %}
template <typename T>
class FenwickTree {
  const int n;
  vector<T> data;
public:
  FenwickTree(int count) : n(count), data(count, 0) {;}
  void add(int pos, const T& value) {
    assert (0 <= pos && pos < n);
    for (int i = pos; i < n; i |= i + 1) data[i] += value;
  }
  T sum(int pos) const {
    assert (0 <= pos && pos <= n);
    T res = 0;
    for (int i = pos - 1; i >= 0; i = (i & (i + 1)) - 1) {
      res += data[i];
    }
    return res;
  }
  T sum(int l, int r) const {
    assert (0 <= l && l <= r && r <= n);
    return sum(r) + (-sum(l));
  }
  using value_type = T;
  using update_type = T;
};
{% endhighlight %}

{% include mathjax.html %}

### Usage

{% highlight cpp %}
(1) FenwickTree<typename T>(int count);
(2) T add(int pos, const T& value);
(3) T sum(int pos) const;
(4) T sum(int l, int r) const;
{% endhighlight %}

- (1): 長さ count の Fenwick Tree を作り，全ての要素を 0 で初期化する．
- (2): pos 番目の要素に値 value を加える．
- (3): 区間 [0, pos) 番目の範囲の和を求める．(pos = 0 のときは 0 を返す．)
- (4): 区間 [l, r) 番目の範囲の和を求める．(l = r のときは 0 を返す．)

### Time Complexity
- (1): $O(n)$
- (2): $O(\log(n))$
- (3): $O(\log(n))$
- (4): $O(\log(n))$

[Back](../..)
