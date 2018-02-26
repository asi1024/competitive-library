#pragma once

#include "fenwick_tree.cpp"

template <typename T>
class RARS {
  FenwickTree<T> bit1, bit2;
public:
  RARS(int count) : bit1(count + 1), bit2(count + 1) {;}
  void add(int l, int r, const T& val) {
    bit1.add(l, -val * l); bit2.add(l,  val);
    bit1.add(r,  val * r); bit2.add(r, -val);
  }
  T sum(int l, int r) const {
    return bit1.sum(l + 1, r + 1) + bit2.sum(r + 1) * r - bit2.sum(l + 1) * l;
  }
};
