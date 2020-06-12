#pragma once

#include <iostream>

#include "../template/bit_operation.cpp"
#include "../template/includes.cpp"

template <typename Struct> class SegmentTreeLazy {
public:
  using Monoid = typename Struct::Monoid;
  using Update = typename Struct::Update;
  using value_type = typename Struct::value_type;
  using update_type = typename Struct::update_type;

private:
  const int size_, n;
  std::vector<value_type> data;
  std::vector<update_type> lazy;
  void apply(int pos, update_type f) {
    data[pos] = Struct::evaluate(data[pos], f);
    if (pos < n) lazy[pos] = Update::op(lazy[pos], f);
  }
  void propagate(int pos) {
    for (int i = lg(pos), end = ctz(pos); i > end; --i) {
      int p = pos >> i;
      apply(2 * p, lazy[p]);
      apply(2 * p + 1, lazy[p]);
      lazy[p] = Update::id();
    }
  }

public:
  SegmentTreeLazy(const std::vector<value_type> &vec) :
    size_(vec.size()), n(log2ceil(size_)), data(n * 2, Monoid::id()),
    lazy(n, Update::id()) {
    std::copy(begin(vec), end(vec), begin(data) + n);
    for (int i = n - 1; i >= 1; i--) {
      data[i] = Monoid::op(data[i * 2 + 0], data[i * 2 + 1]);
    }
  };

  SegmentTreeLazy(int count, const value_type &value = Monoid::id()) :
    SegmentTreeLazy(std::vector<value_type>(count, value)) {}

  int size() const { return size_; }

  void update(int l, int r, const update_type &f) {
    propagate(l += n), propagate(r += n);
    for (int i = l, j = r; i < j; i >>= 1, j >>= 1) {
      if (i & 1) apply(i++, f);
      if (j & 1) apply(--j, f);
    }
    l = l >> ctz(l);
    while (l >>= 1) data[l] = Monoid::op(data[2 * l], data[2 * l + 1]);
    r = r >> ctz(r);
    while (r >>= 1) data[r] = Monoid::op(data[2 * r], data[2 * r + 1]);
  }

  value_type query(int l, int r) {
    propagate(l += n), propagate(r += n);
    value_type a = Monoid::id(), b = Monoid::id();
    for (; l < r; l >>= 1, r >>= 1) {
      if (l & 1) a = Monoid::op(a, data[l++]);
      if (r & 1) b = Monoid::op(data[--r], b);
    }
    return Monoid::op(a, b);
  }
};
