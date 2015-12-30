#pragma once

#include "../util.hpp"

template <typename T>
class SegmentTree {
  using func_t = function<T(T, T)>;
private:
  int n; T id; vector<T> data; func_t merge;
  T sub(int fr, int to, int node, int la, int ra) {
    if (ra<=fr || to<=la) return id;
    if (fr<=la && ra<=to) return data[node];
    T vl = sub(fr, to, (node-n)*2+0, la, (la+ra)/2);
    T vr = sub(fr, to, (node-n)*2+1, (la+ra)/2, ra);
    return merge(vl, vr);
  }
public:
  SegmentTree(int N, T id, func_t f) : n(N), id(id), merge(f) {
    while (n != (n & -n)) n += n & -n;
    data.assign(n * 2, id);
  }
  void update(int pos, T value) {
    data[pos] = value;
    while (pos < 2*n-1) {
      int l = pos, r = pos^1;
      if (l > r) swap(l, r);
      pos = pos / 2 + n;
      data[pos] = merge(data[l], data[r]);
    }
  }
  T find(int fr, int to) {
    return sub(fr, to, 2*n-2, 0, n);
  }
};

// Verified : AOJ DSL_2_A (Range Minimum Query)
/*
int main() {
  int n, q, com, x, y;
  cin >> n >> q;
  SegmentTree<int> seg(n, 0x7FFFFFFF, [](int a, int b){return min(a, b);});
  while (q--) {
    cin >> com >> x >> y;
    if (com) cout << seg.find(x, y+1) << endl;
    else seg.update(x, y);
  }
  return 0;
}
*/
