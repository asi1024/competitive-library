#pragma once

#include "../util.hpp"

template <typename T>
class StarrySkyTree {
  const int n;
  vector<T> data, lazy;
  int expand(int n) const { return n == 1 ? n : expand((n + 1) / 2) * 2; }
public:
  StarrySkyTree(int m) : n(expand(m)), data(n * 2, 0), lazy(n * 2, 0) {}
  void add(int l, int r, T val) {
    l += n; r += n;
    const int left = l, right = r;
    while (l != r) {
      if (l % 2) { lazy[l] += val; data[l++] += val; }
      if (r % 2) { lazy[--r] += val; data[r] += val; }
      l /= 2; r /= 2;
    }
    l = left; r = right - 1;
    while (l /= 2, r /= 2) {
      data[l] = min(data[l * 2], data[l * 2 + 1]) + lazy[l];
      data[r] = min(data[r * 2], data[r * 2 + 1]) + lazy[r];
    }
  }
  T minimum(int l, int r) const {
    l += n; r += n;
    T res1 = inf<T>, res2 = inf<T>;
    while (l != r) {
      if (l % 2) res1 = min(res1, data[l++]);
      if (r % 2) res2 = min(res2, data[--r]);
      l /= 2; r /= 2;
      res1 += lazy[l - 1];
      res2 += lazy[r];
    }
    --l;
    while (l /= 2, r /= 2) {
      res1 += lazy[l];
      res2 += lazy[r];
    }
    return min(min(res1, res2), inf<T>);
  }
};
