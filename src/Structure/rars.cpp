#pragma once

#include "fenwick_tree.cpp"

template <typename T>
class RARS {
  FenwickTree<T> bit1, bit2;
public:
  RARS(int n) : bit1(n+1), bit2(n+1) {}
  void add(int l, int r, T val) {
    bit1.add(l, -val * l);
    bit1.add(r,  val * r);
    bit2.add(l,  val);
    bit2.add(r, -val);
  }
  T sum(int l, int r) {
    T s1 = bit1.sum(r) + bit2.sum(r) * r;
    T s2 = bit1.sum(l) + bit2.sum(l) * l;
    return s1 - s2;
  }
};
