#pragma once

#include "../util.hpp"

template <typename T>
class FenwickTree {
  const int n;
  vector<T> data;
public:
  FenwickTree(int count) : n(count), data(count, 0) {;}
  void add(int pos, const T& value) {
    for (int i = pos; i < n; i |= i + 1) data[i] += value;
  }
  T sum(int pos) const {
    T res = 0;
    for (int i = pos; i >= 0; i = (i & (i + 1)) - 1) res += data[i];
    return res;
  }
  T sum(int l, int r) const { return sum(r - 1) + (-sum(l - 1)); }
};
