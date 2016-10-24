#pragma once

#include "../util.hpp"

template <typename T>
class StarrySkyTree {
  const int n;
  vector<T> data, lazy;
  void add_sub(int l, int r, int node, int lb, int ub, T val) {
    if (ub <= l || r <= lb) return;
    if (l <= lb && ub <= r) { lazy[node] += val; return; }
    int left = node * 2, right = left + 1;
    add_sub(l, r, left, lb, (lb + ub) / 2, val);
    add_sub(l, r, right, (lb + ub) / 2, ub, val);
    data[node] = min(data[left] + lazy[left], data[right] + lazy[right]);
  }
  T min_sub(int l, int r, int node, int lb, int ub) {
    if (ub <= l || r <= lb) return inf<T>;
    if (l <= lb && ub <= r) return data[node] + lazy[node];
    T vl = min_sub(l, r, node * 2 + 0, lb, (lb + ub) / 2);
    T vr = min_sub(l, r, node * 2 + 1, (lb + ub) / 2, ub);
    return lazy[node] + min(vl, vr);
  }
  int size(int n) {
    return n == 1 ? n : size((n + 1) / 2) * 2;
  }
public:
  StarrySkyTree(int m) : n(size(m)), data(n * 2, 0), lazy(n * 2, 0) {}
  void add(int l, int r, T val) { add_sub(l, r, 1, 0, n, val); }
  T minimum(int l, int r) { return min_sub(l, r, 1, 0, n); }
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
      if (l > r) cout << min(seg.minimum(l, N), seg.minimum(0, r+1)) << endl;
      else cout << seg.minimum(l, r+1) << endl;
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
