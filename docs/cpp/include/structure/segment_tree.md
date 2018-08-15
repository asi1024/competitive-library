{% include mathjax.html %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
SegmentTree(const std::vector< value_type > &vec);
SegmentTree(const int count, const value_type &value=Monoid::id());
{% endhighlight %}

- vector 型の列 vec を表現するセグメント木を作る．
- 長さ count のセグメント木を作り，全ての要素を value で初期化する．

#### Parameters

|:--:|:--|
|vec|ベクトル|
|count|構築するセグメント木の長さ|
|value|各要素の初期値|

#### Time complexity

- $O(n)$

---------------------------------------

### [2] query
{% highlight cpp %}
query(int l, int r) const;
{% endhighlight %}

- セグメント木の区間 [l, r) を演算 Monoid::op ($\cdot$) で畳み込んだ値を返す． すなわち，$a_l \cdot a_{l+1} \cdot \ldots \cdot a_{r-1}$ を返す． $l = r$ の場合は Monoid::id() を返す．

#### Time complexity

- $O(\log n)$

---------------------------------------

### [3] size
{% highlight cpp %}
int size() const;
{% endhighlight %}


#### Return value

- セグメント木のサイズを返す．

#### Time complexity

- $O(1)$

---------------------------------------

### [4] update
{% highlight cpp %}
void update(int pos, const value_type &value);
{% endhighlight %}

- pos 番目の要素を value に更新する． その範囲を超えた場合は例外を送出する．

#### Parameters

|:--:|:--|
|pos|pos|
|value|value|

#### Notes

- pos はセグメント木のサイズ未満の非負整数である必要がある．

#### Time complexity

- $O(\log n)$

---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/segment_tree.cpp)

{% highlight cpp %}
#include "../template/bit_operation.cpp"
#include "../template/includes.hpp"

template <class Monoid> class SegmentTree {
public:
  using value_type = typename Monoid::value_type;
  using update_type = typename Monoid::value_type;

private:
  const int size_, n;
  std::vector<value_type> data;

public:
  SegmentTree(const std::vector<value_type> &vec) :
    size_(vec.size()), n(log2ceil(size_)), data(n * 2, Monoid::id()) {
    std::copy(begin(vec), end(vec), begin(data) + n);
    for (int i = n - 1; i >= 0; --i) {
      data[i] = Monoid::op(data[i * 2 + 0], data[i * 2 + 1]);
    }
  }

  SegmentTree(const int count, const value_type &value = Monoid::id()) :
    SegmentTree(std::vector<value_type>(count, value)) {}

  int size() const { return size_; }

  void update(int pos, const value_type &value) {
    assert(0 <= pos && pos < size_);  // assertion
    data[pos += n] = value;
    while (pos /= 2) {
      data[pos] = Monoid::op(data[pos * 2], data[pos * 2 + 1]);
    }
  }

  value_type query(int l, int r) const {
    assert(0 <= l && l <= r && r <= size_);  // assertion
    l += n;
    r += n;
    value_type res1 = Monoid::id(), res2 = Monoid::id();
    while (l < r) {
      if (l & 1) res1 = Monoid::op(res1, data[l++]);
      if (r & 1) res2 = Monoid::op(data[--r], res2);
      l >>= 1;
      r >>= 1;
    }
    return Monoid::op(res1, res2);
  }
};
{% endhighlight %}

### Includes

- [bit_operation.cpp](../template/bit_operation)
- [includes.hpp](../template/includes)

[Back](../..)
