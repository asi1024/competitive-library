#pragma once

#include "../template/includes.cpp"
#include "../template/typedef.cpp"

class RollingHash {
  const int n;
  static const ll moda = 1000000000000037LL;
  static const ll modb = 1000000000000091LL;
  static const ll pa = 17LL;
  static const ll pb = 19LL;
  std::vector<ll> a, b, p, q;

public:
  template <typename string_t>
  RollingHash(const string_t &str) :
    n(str.size()), a(n + 1, 0), b(n + 1, 0), p(n + 1, 1), q(n + 1, 1) {
    for (int i = 0; i < n; ++i) {
      a[i + 1] = (a[i] * pa + ll(str[i])) % moda;
      b[i + 1] = (b[i] * pb + ll(str[i])) % modb;
      p[i + 1] = p[i] * pa % moda;
      q[i + 1] = q[i] * pb % modb;
    }
  }
  std::pair<ll, ll> query(int l, int r) {
    return std::make_pair(((__int128)p[r - l] * a[l] - a[r] + moda) % moda,
                          ((__int128)q[r - l] * b[l] - b[r] + modb) % modb);
  }
};
