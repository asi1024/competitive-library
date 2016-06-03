#pragma once

#include "../util.hpp"

template<int M>
class Cyclic {
  using ll = long long;
  int n;
  static ll inv(ll a, ll p) { return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p); }
public:
  Cyclic () : n(0) {;}
  Cyclic (int m) : n(m) {
    if (n >= M) n %= M;
    else if (n < 0) n = (n % M + M) % M;
  }
  operator int() const { return n; }
  bool operator==(const Cyclic &a) const { return n == a.n; }
  Cyclic operator+=(const Cyclic &a) { n += a.n; if (n >= M) n -= M; return *this; }
  Cyclic operator-=(const Cyclic &a) { n -= a.n; if (n < 0) n += M; return *this; }
  Cyclic operator*=(const Cyclic &a) { n = (ll(n) * a.n) % M; return *this; }
  Cyclic operator+(const Cyclic &a) const { Cyclic res = *this; return res += a; }
  Cyclic operator-(const Cyclic &a) const { Cyclic res = *this; return res -= a; }
  Cyclic operator*(const Cyclic &a) const { Cyclic res = *this; return res *= a; }
  Cyclic operator/(const Cyclic &a) const { return *this * Cyclic<M>(inv(a, M)); }
  Cyclic operator^(int n) const {
    if (n == 0) return Cyclic(1);
    const Cyclic a = *this;
    Cyclic res = (a * a) ^ (n / 2);
    return n % 2 ? res * a : res;
  }
};

template<int M> Cyclic<M> fact(int n, bool sw = true) {
  static vector<Cyclic<M>> v1 = {1}, v2 = {1};
  if (n > (int)v1.size()) {
    const int from = v1.size(), to = n + 1;
    v1.resize(to);
    v2.resize(to);
    for (int i = from; i < to; ++i) {
      v1[i] = v1[i-1] * Cyclic<M>(i);
      v2[i] = v2[i-1] / Cyclic<M>(i);
    }
  }
  return sw ? v1[n] : v2[n];
}

template<int M> Cyclic<M> comb(int a, int b) {
  return fact<M>(a, true) * fact<M>(b, false) * fact<M>(a-b, false);
}

const int mod = 1000000007;
using Mod = Cyclic<mod>;
