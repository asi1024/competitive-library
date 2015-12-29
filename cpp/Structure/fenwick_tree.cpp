#pragma once

#include "../util.hpp"

// Verified : AOJ DSL_2_B (Range Sum Query)

template <typename T>
struct FenwickTree {
  int n;
  vector<T> data;
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
struct RARS {
  FenwickTree<T> bit1, bit2;
  RARS(int n) : bit1(n+1), bit2(n+1) {}
  void add(int fr, int to, T val) {
    bit1.update(fr, -val * fr);
    bit1.update(to, val * to);
    bit2.update(fr, val);
    bit2.update(to, -val);
  }
  T sum(int fr, int to) {
    T s1 = bit1.sum(to) + bit2.sum(to) * to;
    T s2 = bit1.sum(fr) + bit2.sum(fr) * fr;
    return s1 - s2;
  }
};

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
