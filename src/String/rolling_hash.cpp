#pragma once

#include "../util.hpp"

using ll = long long;

vector<ll> inv_list;

class RollingHash {
  static const ll mod = 1000000000000037LL;
  static const ll v = 17LL, w = 529411764705902LL;
  const int n;
  vector<ll> a;
public:
  RollingHash (string str) : n(str.size()), a(n + 1, 0) {
    for (int i = 0; i < n; ++i)
      a[i+1] = (a[i] * v + str[i]) % mod;
    int m = inv_list.size() - 1;
    if (n > m) {
      inv_list.resize(n + 1);
      for (int i = m; i < n; ++i)
        inv_list[i+1] = (inv_list[i] * __int128(w)) % mod;
    }
  }
  ll query(int l, int r) {
    return (a[r] - a[l]) * __int128(inv_list[l]);
  }
};
