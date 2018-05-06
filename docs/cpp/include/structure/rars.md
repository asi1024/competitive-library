{% include mathjax.html %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
RARS(int count);
{% endhighlight %}

- 長さ count の列を作り，全ての要素を 0 で初期化する． 

#### Time complexity

- $O(n)$

---------------------------------------

### [2] query
{% highlight cpp %}
T query(int l, int r) const;
{% endhighlight %}

- 区間 [l, r) 番目の範囲の和を求める． 

#### Time complexity

- $O(\log(n))$

---------------------------------------

### [3] update
{% highlight cpp %}
void update(int l, int r, const T &val);
{% endhighlight %}

- 区間 [l, r) 番目の要素に値 value を加える． 

#### Time complexity

- $O(\log(n))$

---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/rars.cpp)

{% highlight cpp %}
#include "fenwick_tree.cpp"

template <typename T>
class RARS {
  const int n;
  FenwickTree<T> bit1, bit2;
public:
  RARS(int count) : n(count), bit1(n + 1), bit2(n + 1) {;}
  void update(int l, int r, const T& val) {
    assert (0 <= l && l <= r && r <= n);
    bit1.add(l, -val * l); bit2.add(l,  val);
    bit1.add(r,  val * r); bit2.add(r, -val);
  }
  T query(int l, int r) const {
    assert (0 <= l && l <= r && r <= n);
    return bit1.sum(l + 1, r + 1) + bit2.sum(r + 1) * r - bit2.sum(l + 1) * l;
  }
  using value_type = T;
  using update_type = T;
};
{% endhighlight %}

### Includes

- [fenwick_tree.cpp](fenwick_tree)

[Back](../..)
