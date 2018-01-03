#pragma once

#include "../util.hpp"
#include "mod.cpp"

template<int prim_root, int mod, int sign>
void FMT(vector<Modulo<mod, true>> &a) {
  using Mod = Modulo<mod, true>;
  const int n = a.size();
  Mod h = Mod(prim_root) ^ ((mod - 1) / n);
  if (sign == -1) h = Mod(1) / h;
  int x = 0;
  for (int i = 1; i < n - 1; ++i) {
    for (int j = n / 2; j > (x ^= j); j /= 2);
    if (i < x) swap(a[x], a[i]);
  }
  for (int m = 1; m < n; m *= 2) {
    const int m2 = 2 * m;
    const Mod base = Mod(h) ^ (n / m2);
    Mod w = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = i; j < n; j += m2) {
        const Mod u = a[j], d = a[j + m] * w;
        a[j] = u + d;
        a[j + m] = u - d;
      }
      w *= base;
    }
  }
}

template<int prim_root, int mod>
vector<Modulo<mod, true>> convolution(vector<Modulo<mod, true>> a,
                                      vector<Modulo<mod, true>> b) {
  using Mod = Modulo<mod, true>;
  int size = a.size() + b.size();
  while ((size & -size) != size) size += (size & -size);
  a.resize(size); FMT<prim_root, mod, 1>(a);
  b.resize(size); FMT<prim_root, mod, 1>(b);
  for (int i = 0; i < size; ++i) a[i] *= b[i];
  FMT<prim_root, mod, -1>(a);
  const Mod inv = Mod(1) / Mod(size);
  for (auto &x : a) x *= inv;
  return a;
}
