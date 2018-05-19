#pragma once

#include "../util.hpp"

template <typename T> class FenwickTree {
  const int n;
  vector<T> data;

public:
  /// @brief
  /// 長さ count の Fenwick Tree を作り，全ての要素を 0 で初期化する．
  /// @complexity $O(n)$
  FenwickTree(int count) : n(count), data(count, 0) { ; }

  /// @brief
  /// pos 番目の要素に値 value を加える．
  /// @complexity $O(\\log(n))$
  void add(int pos, const T &value) {
    assert(0 <= pos && pos < n);
    for (int i = pos; i < n; i |= i + 1) data[i] += value;
  }

  /// @brief
  /// 区間 [0, pos) 番目の範囲の和を求める．(pos = 0 のときは 0 を返す．)
  /// @complexity $O(\\log(n))$
  T sum(int pos) const {
    assert(0 <= pos && pos <= n);
    T res = 0;
    for (int i = pos - 1; i >= 0; i = (i & (i + 1)) - 1) {
      res += data[i];
    }
    return res;
  }

  /// @brief
  /// 区間 [l, r) 番目の範囲の和を求める．(l = r のときは 0 を返す．)
  /// @complexity $O(\\log(n))$
  T sum(int l, int r) const {
    assert(0 <= l && l <= r && r <= n);
    return sum(r) + (-sum(l));
  }
  using value_type = T;
  using update_type = T;
};
