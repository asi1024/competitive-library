#pragma once

#include "../util.hpp"

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
