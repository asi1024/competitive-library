---
title: "segment_tree.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/segment_tree.cpp)

{% highlight cpp %}
#include "../template/bit_operation.cpp"
#include "../template/includes.cpp"

template <class Monoid> class SegmentTree {
public:
  using value_type = typename Monoid::value_type;
  using update_type = typename Monoid::value_type;

private:
  const int size_, n;
  std::vector<value_type> data;
  using iterator = typename std::vector<value_type>::iterator;

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

  std::deque<iterator> range_iterators(int l, int r) {
    assert(0 <= l && l <= r && r <= size_);  // assertion
    l += n;
    r += n;
    std::deque<iterator> res;
    while (l < r) {
      if (l & 1) res.push_front(data.begin() + l++);
      if (r & 1) res.push_back(data.begin() + --r);
      l >>= 1;
      r >>= 1;
    }
    return res;
  }
};
{% endhighlight %}

### Includes

- [bit_operation.cpp](../template/bit_operation)
- [includes.cpp](../template/includes)

[Back](../..)
