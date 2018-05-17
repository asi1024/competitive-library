#pragma once

#include "../template/includes.hpp"

template <class Monoid> class SegmentTree {
public:
  using value_type = typename Monoid::value_type;
  using update_type = typename Monoid::value_type;

private:
  const int size_, n;
  std::vector<value_type> data;
  int expand(int m) const { return m == 1 ? m : expand((m + 1) / 2) * 2; }

public:
  /// @complexity $O(n)$
  /// @param vec: ベクトル
  /// @brief
  /// vector 型の列 vec を表現するセグメント木を作る．
  SegmentTree(const std::vector<value_type> &vec)
      : size_(vec.size()), n(expand(size_)), data(n * 2, Monoid::id()) {
    std::copy(begin(vec), end(vec), begin(data) + n);
    for (int i = n - 1; i >= 0; --i) {
      data[i] = Monoid::op(data[i * 2 + 0], data[i * 2 + 1]);
    }
  }

  /// @complexity $O(n)$
  /// @param count: 構築するセグメント木の長さ
  /// @param value: 各要素の初期値
  /// @brief
  /// 長さ count のセグメント木を作り，全ての要素を value で初期化する．
  SegmentTree(const int count, const value_type &value = Monoid::id())
      : SegmentTree(std::vector<value_type>(count, value)) {}

  /// @complexity $O(1)$
  /// @return セグメント木のサイズを返す．
  int size() const { return size_; }

  /// @complexity $O(\\log n)$
  /// @param pos: pos
  /// @param value: value
  /// @brief
  /// pos 番目の要素を value に更新する．
  /// その範囲を超えた場合は例外を送出する．
  /// @note pos はセグメント木のサイズ未満の非負整数である必要がある．
  void update(int pos, const value_type &value) {
    assert(0 <= pos && pos < size_); // assertion
    data[pos += n] = value;
    while (pos /= 2) {
      data[pos] = Monoid::op(data[pos * 2], data[pos * 2 + 1]);
    }
  }

  /// @complexity $O(\\log n)$
  /// @brief
  /// セグメント木の区間 [l, r) を演算 Monoid::op ($\\cdot$)
  /// で畳み込んだ値を返す． すなわち，$a_l \\cdot a_{l+1} \\cdot \\ldots \\cdot
  /// a_{r-1}$ を返す． $l = r$ の場合は Monoid::id() を返す．
  value_type query(int l, int r) const {
    assert(0 <= l && l <= r && r <= size_); // assertion
    l += n;
    r += n;
    value_type res1 = Monoid::id(), res2 = Monoid::id();
    while (l != r) {
      if (l % 2)
        res1 = Monoid::op(res1, data[l++]);
      if (r % 2)
        res2 = Monoid::op(data[--r], res2);
      l /= 2;
      r /= 2;
    }
    return Monoid::op(res1, res2);
  }
};
