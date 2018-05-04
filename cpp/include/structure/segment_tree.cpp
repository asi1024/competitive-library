#pragma once

#include "../util.hpp"

template <class Monoid>
class SegmentTree {
  using T = typename Monoid::type;
  const int size_, n;
  std::vector<T> data;
  int expand(int m) const { return m == 1 ? m : expand((m + 1) / 2) * 2; }
public:
  /// @complexity $O(n)$
  /// @brief
  /// vector 型の列 vec を表現するセグメント木を作る．
  SegmentTree(const std::vector<T> &vec) :
    size_(vec.size()), n(expand(size_)), data(n * 2, Monoid::id()) {
    std::copy(begin(vec), end(vec), begin(data) + n);
    for (int i = n - 1; i >= 0; --i) {
      data[i] = Monoid::op(data[i * 2 + 0], data[i * 2 + 1]);
    }
  }


  /// @complexity $O(n)$
  /// @brief
  /// 長さ count のセグメント木を作り，全ての要素を value で初期化する．
  SegmentTree(const int count, const T &value = Monoid::id()) :
    SegmentTree(std::vector<T>(count, value)) {}


  /// @complexity $O(1)$
  /// @brief
  /// セグメント木のサイズを返す．
  int size() const { return size_; }

  /// @complexity $O(\\log n)$
  /// @brief
  /// pos 番目の要素を value に更新する．
  /// その範囲を超えた場合は例外を送出する．
  /// @pre pos はセグメント木のサイズ未満の非負整数である必要がある．
  void update(int pos, const T &value) {
    assert (0 <= pos && pos < size_); // assertion
    data[pos += n] = value;
    while (pos /= 2) {
      data[pos] = Monoid::op(data[pos * 2], data[pos * 2 + 1]);
    }
  }

  /// @complexity $O(\\log n)$
  /// @brief
  /// セグメント木の区間 [l, r) を演算 Monoid::op ($\\cdot$) で畳み込んだ値を返す．
  /// すなわち，$a_l \\cdot a_{l+1} \\cdot \\ldots \\cdot a_{r-1}$ を返す．
  /// $l = r$ の場合は Monoid::id() を返す．
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
  using value_type = T;
  using update_type = T;
};

struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(const type &l, const type &r) { return min(l, r); }
};
