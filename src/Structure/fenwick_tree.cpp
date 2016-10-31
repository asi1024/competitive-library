#pragma once

#include "../util.hpp"

template <typename T>
class FenwickTree {
  const int n;
  vector<T> data;
public:
  FenwickTree(int n) : n(n), data(n, 0) {}
  void add(int i, T value) {
    for (; i < n; i |= i+1) data[i] += value;
  }
  T sum(int i) const {
    T s = 0;
    for (; i >= 0; i = (i&(i+1))-1) s += data[i];
    return s;
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
    else bit.add(x, y);
  }
  return 0;
}
*/
