#pragma once

#include "../util.hpp"

template <typename T>
class FenwickTree {
  const int n;
  vector<T> data;
public:
  FenwickTree(int n) : n(n), data(n, 0) {}
  void update(int i, T value) {
    for (; i < n; i |= i+1) data[i] += value;
  }
  T sum(int i) {
    T s = 0;
    for (; i >= 0; i = (i&(i+1))-1) s += data[i];
    return s;
  }
};

template <typename T>
class RARS {
  FenwickTree<T> bit1, bit2;
public:
  RARS(int n) : bit1(n+1), bit2(n+1) {}
  void add(int l, int r, T val) {
    bit1.update(l, -val * l);
    bit1.update(r,  val * r);
    bit2.update(l,  val);
    bit2.update(r, -val);
  }
  T sum(int l, int r) {
    T s1 = bit1.sum(r) + bit2.sum(r) * r;
    T s2 = bit1.sum(l) + bit2.sum(l) * l;
    return s1 - s2;
  }
};

// Verified : AOJ DSL_2_B (Range Sum Query)
/*
int main() {
  int n, q, com, x, y;
  cin >> n >> q;
  FenwickTree<int> bit(n+1);
  while (q--) {
    cin >> com >> x >> y;
    if (com) cout << bit.sum(y) - bit.sum(x-1) << endl;
    else bit.update(x, y);
  }
  return 0;
}
*/
