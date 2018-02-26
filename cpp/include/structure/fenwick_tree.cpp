#pragma once

#include "../util.hpp"

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
};
