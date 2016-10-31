#pragma once

#include "../util.hpp"

template <typename T, const T& merge(const T&, const T&)>
class SegmentTree {
  const int n;
  const T id;
  vector<T> data;
  T sub(int l, int r, int node, int lb, int ub) const {
    if (ub <= l || r <= lb) return id;
    if (l <= lb && ub <= r) return data[node];
    T vl = sub(l, r, node * 2 + 0, lb, (lb + ub) / 2);
    T vr = sub(l, r, node * 2 + 1, (lb + ub) / 2, ub);
    return merge(vl, vr);
  }
  int size(int n) const {
    return n == 1 ? n : size((n + 1) / 2) * 2;
  }
public:
  SegmentTree(int m, T id) : n(size(m)), id(id), data(n * 2, id) {}
  void update(int p, T val) {
    assert (0 <= p && p < n);
    p += n;
    data[p] = val;
    while (p /= 2) {
      int l = p * 2, r = p * 2 + 1;
      data[p] = merge(data[l], data[r]);
    }
  }
  T find(int l, int r) const {
    return sub(l, r, 1, 0, n);
  }
};

// Verified : AOJ DSL_2_A (Range Minimum Query)
/*
int main() {
  int n, q, com, x, y;
  cin >> n >> q;
  SegmentTree<int,min> seg(n, 0x7FFFFFFF);
  while (q--) {
    cin >> com >> x >> y;
    if (com) cout << seg.find(x, y+1) << endl;
    else seg.update(x, y);
  }
  return 0;
}
*/
