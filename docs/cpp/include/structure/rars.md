## rars.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/rars.cpp)

### Includes

- [fenwick_tree.cpp](fenwick_tree)

{% highlight cpp %}
#include "fenwick_tree.cpp"

template <typename T>
class RARS {
  FenwickTree<T> bit1, bit2;
public:
  RARS(int count) : bit1(n+1), bit2(n+1) {}
  void add(int l, int r, const T& val) {
    bit1.add(l, -val * l); bit2.add(l,  val);
    bit1.add(r,  val * r); bit2.add(r, -val);
  }
  T sum(int l, int r) const {
    T rsum = bit1.sum(r) + bit2.sum(r) * r;
    T lsum = bit1.sum(l) + bit2.sum(l) * l;
    return rsum - lsum;
  }
};
{% endhighlight %}

{% include mathjax.html %}

### Usage

{% highlight cpp %}
(1) RARS<typename T>(int count);
(2) T add(int l, int r, const T& value);
(4) T sum(int l, int r) const;
{% endhighlight %}

- (1): 長さ count の Fenwick Tree を作り，全ての要素を 0 で初期化する．
- (2): 区間 [l, r) 番目の要素に値 value を加える．
- (3): 区間 [l, r) 番目の範囲の和を求める．

### Time Complexity
- (1): $O(n)$
- (3): $O(\log(n))$
- (4): $O(\log(n))$

[Back](../..)
