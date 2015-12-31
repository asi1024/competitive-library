#pragma once

#include "../util.hpp"

template <typename T>
class StarrySkyTree {
  static const T INF = 0x7FFFFFFF;
  int n; vector<T> data, lazy;
  void upd_sub(int fr, int to, int node, int la, int ra, T val) {
    if (ra<=fr || to<=la) return;
    if (fr<=la && ra<=to) { lazy[node] += val; return; }
    int left = (node - n) * 2, right = left + 1;
    upd_sub(fr, to, left, la, (la+ra)/2, val);
    upd_sub(fr, to, right, (la+ra)/2, ra, val);
    data[node] = min(data[left] + lazy[left], data[right] + lazy[right]);
  }
  T min_sub(int fr, int to, int node, int la, int ra) {
    if (ra<=fr || to<=la) return INF;
    if (fr<=la && ra<=to) return data[node] + lazy[node];
    T vl = min_sub(fr, to, (node-n)*2+0, la, (la+ra)/2);
    T vr = min_sub(fr, to, (node-n)*2+1, (la+ra)/2, ra);
    return lazy[node] + min(vl, vr);
  }
public:
  StarrySkyTree(int N) : n(N) {
    while (n != (n & -n)) n += n & -n;
    data.assign(n * 2, 0);
    lazy.assign(n * 2, 0);
  }
  void add(int fr, int to, T val) { upd_sub(fr, to, 2*n-2, 0, n, val); }
  T min_element(int fr, int to) { return min_sub(fr, to, 2*n-2, 0, n); }
};

// Verified : Codeforces 52C (Circular RMQ)
/*
char str[2048000];

vector<int> get_int() {
  fgets(str, 2048000, stdin);
  vector<int> res;
  int n = 0;
  bool flag = false;
  for (int i = 0;; ++i) {
    if (str[i] == '-') { flag = true; ++i; }
    if (str[i] == ' ' || str[i] == '\n') {
      if (flag) n = -n;
      res.push_back(n); n = 0; flag = false;
    }
    else {
      n = n * 10 + (int)(str[i] - '0');
    }
    if (str[i] == '\n') break;
  }
  return res;
}

using ll = long long;

int main() {
  int N = get_int()[0];
  StarrySkyTree<ll> seg(N);
  vector<int> a = get_int();
  for (int i = 0; i < N; ++i) seg.add(i, i+1, a[i]);
  int Q = get_int()[0];
  while (Q--) {
    vector<int> com = get_int();
    int l = com[0], r = com[1];
    if (com.size() == 2) {
      if (l > r) cout << min(seg.min_element(l, N),
                             seg.min_element(0, r+1)) << endl;
      else cout << seg.min_element(l, r+1) << endl;
    }
    else {
      ll v = com[2];
      if (l > r) { seg.add(l, N, v); seg.add(0, r+1, v); }
      else seg.add(l, r+1, v);
    }
  }
  return 0;
}
*/
