#pragma once

#include "../util.hpp"

template<int M, bool IsPrime = false>
class Modulo {
  using ll = long long;
  int n;
  static enable_if_t<IsPrime, ll> inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
  }
public:
  Modulo () : n(0) {;}
  Modulo (int m) : n(m) {
    if (n >= M) n %= M;
    else if (n < 0) n = (n % M + M) % M;
  }
  Modulo (ll m) {
    if (m >= M) m %= M;
    else if (m < 0) m = (m % M + M) % M;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator ll() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo operator+=(const Modulo &a) { n += a.n; if (n >= M) n -= M; return *this; }
  Modulo operator-=(const Modulo &a) { n -= a.n; if (n < 0) n += M; return *this; }
  Modulo operator*=(const Modulo &a) { n = (ll(n) * a.n) % M; return *this; }
  Modulo operator+(const Modulo &a) const { Modulo res = *this; return res += a; }
  Modulo operator-(const Modulo &a) const { Modulo res = *this; return res -= a; }
  Modulo operator*(const Modulo &a) const { Modulo res = *this; return res *= a; }
  Modulo operator^(int n) const {
    if (n == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (n / 2);
    return n % 2 ? res * a : res;
  }
  enable_if_t<IsPrime, Modulo> operator/(const Modulo &a) const {
    return *this * inv(ll(a), M);
  }
};

template<int M> Modulo<M, true> fact(int n, bool sw = true) {
  static vector<Modulo<M, true>> v1 = {1}, v2 = {1};
  if (n >= (int)v1.size()) {
    const int from = v1.size(), to = n + 1024;
    v1.reserve(to);
    v2.reserve(to);
    for (int i = from; i < to; ++i) {
      v1.push_back(v1.back() * Modulo<M, true>(i));
      v2.push_back(v2.back() / Modulo<M, true>(i));
    }
  }
  return sw ? v1[n] : v2[n];
}

template<int M> Modulo<M, true> comb(int a, int b) {
  if (b < 0 || b > a) return 0;
  return fact<M>(a, true) * fact<M>(b, false) * fact<M>(a-b, false);
}

const int mod = 1000000007;
using Mod = Modulo<mod, true>;

// Verified : ABC 003D
/*
Mod solve(int x, int y, int d, int l) {
  if (x <= 0 || y <= 0 || d + l > x * y) return Mod(0);
  int num = x * y;
  return fact<mod>(num) * fact<mod>(d, false) *
    fact<mod>(l, false) * fact<mod>(num - l - d, false);
}

int main() {
  int R, C, X, Y, D, L;
  cin >> R >> C >> X >> Y >> D >> L;
  Mod a = Mod(R - X + 1) * Mod(C - Y + 1);
  Mod b = solve(X, Y, D, L);
  b -= solve(X-1, Y, D, L) * Mod(2);
  b -= solve(X, Y-1, D, L) * Mod(2);
  b += solve(X-2, Y, D, L);
  b += solve(X, Y-2, D, L);
  b += solve(X-1, Y-1, D, L) * Mod(4);
  b -= solve(X-2, Y-1, D, L) * Mod(2);
  b -= solve(X-1, Y-2, D, L) * Mod(2);
  b += solve(X-2, Y-2, D, L);
  cout << ll(a * b) << endl;
  return 0;
}
*/
