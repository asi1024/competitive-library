## segment_tree.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/segment_tree.cpp)

```cpp
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
```

- [Back](https://{{ site.github.owner_name }}.github.io/competitive-library)
