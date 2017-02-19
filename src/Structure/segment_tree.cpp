#pragma once

#include "../util.hpp"

template <class T>
class SegmentTree {
  const int sz, n;
  std::vector<T> data;
  int expand(int n) const { return n == 1 ? n : expand((n + 1) / 2) * 2; }
public:
  SegmentTree(const std::vector<T> &init) :
    sz(init.size()), n(expand(sz)), data(n * 2, T()) {
    std::copy(begin(init), end(init), begin(data));
    for (int i = n - 1; i >= 0; --i) {
      data[i] = merge(data[i * 2 + 0], data[i * 2 + 1]);
    }
  }
  int size() const { return sz; }
  void update(int p, T val) {
    assert (0 <= p && p < sz); // assertion
    data[p += n] = val;
    while (p /= 2) data[p] = merge(data[p * 2], data[p * 2 + 1]);
  }
  T find(int l, int r) const {
    assert (0 <= l && l <= r && r <= sz); // assertion
    l += n; r += n;
    T res1 = T(), res2 = T();
    while (l != r) {
      if (l % 2) res1 = merge(res1, data[l++]);
      if (r % 2) res2 = merge(data[--r], res2);
      l /= 2; r /= 2;
    }
    return merge(res1, res2);
  }
};

// Verified : AOJ DSL_2_A (Range Minimum Query) 0.02sec
/*
struct Data {
  int n;
  Data() : n(INT_MAX) {}
  Data(int n) : n(n) {}
};

Data merge(const Data &a, const Data &b) {
  return Data(min(a.n, b.n));
}

int main() {
  int n, q, com, x, y;
  scanf("%d%d", &n, &q);
  SegmentTree<Data> seg(vector<Data>(n, Data()));
  while (q--) {
    scanf("%d%d%d", &com, &x, &y);
    if (com) printf("%d\n", seg.find(x, y+1).n);
    else seg.update(x, Data(y));
  }
  return 0;
}
*/
