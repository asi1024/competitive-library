#pragma once

#include "../util.hpp"

// Verified : AOJ DSL_2_A (Range Minimum Query)

struct Data {
  int num;
  Data() : num(0x7FFFFFFF) {;}
  Data(int n) : num(n) {;}
};

inline Data Merge(Data left, Data right) {
  return Data(left.num < right.num ? left.num : right.num);
}

class SegmentTree {
private:
  int n; vector<Data> data;
  Data sub(int fr, int to, int node, int la, int ra) {
    if (ra<=fr || to<=la) return Data();
    if (fr<=la && ra<=to) return data[node];
    Data vl = sub(fr, to, (node-n)*2+0, la, (la+ra)/2);
    Data vr = sub(fr, to, (node-n)*2+1, (la+ra)/2, ra);
    return Merge(vl, vr);
  }
public:
  SegmentTree(int N) : n(N) {
    while (n != (n & -n)) n += n & -n;
    data.assign(n * 2, Data());
  }
  void update(int pos, Data value) {
    data[pos] = value;
    while (pos < 2*n-1) {
      int l = pos, r = pos^1;
      if (l > r) swap(l, r);
      pos = pos / 2 + n;
      data[pos] = Merge(data[l], data[r]);
    }
  }
  Data find(int fr, int to) {
    return sub(fr, to, 2*n-2, 0, n);
  }
};

/*
int main() {
  int n, q, com, x, y;
  cin >> n >> q;
  SegmentTree seg(n);
  while (q--) {
    cin >> com >> x >> y;
    if (com) cout << seg.find(x, y+1).num << endl;
    else seg.update(x, Data(y));
  }
  return 0;
}
*/
