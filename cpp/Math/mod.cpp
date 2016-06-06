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
  if (n >= (int)v1.size()) {
    const int from = v1.size(), to = n + 1024;
    v1.reserve(to);
    v2.reserve(to);
    for (int i = from; i < to; ++i) {
      v1.push_back(v1.back() * Cyclic<M>(i));
      v2.push_back(v2.back() / Cyclic<M>(i));
    }
  }
  return sw ? v1[n] : v2[n];
}

template<int M> Cyclic<M> comb(int a, int b) {
  return fact<M>(a, true) * fact<M>(b, false) * fact<M>(a-b, false);
}

const int mod = 1000000007;
using Mod = Cyclic<mod>;

// Verified : ABC 003D
/*
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
  cout << a * b << endl;
  return 0;
}
*/
