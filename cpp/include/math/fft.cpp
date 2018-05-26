#pragma once

#include "../template/const_value.hpp"
#include "../template/includes.hpp"
#include "../template/typedefs.hpp"

std::vector<Point> FFT(const std::vector<Point> &a, int m) {
  ld theta = 2.0 * pi / m;
  const int n = a.size();
  std::vector<Point> res = a;
  for (int m = n; m >= 2; m /= 2, theta *= 2) {
    for (int i = 0; i < m / 2; ++i) {
      for (int j = i; j < n; j += m) {
        int k = j + m / 2;
        Point x = res[j] - res[k];
        res[j] += res[k];
        res[k] = exp(i * theta * Point(0, 1)) * x;
      }
    }
  }
  for (int i = 0, j = 1; j < n - 1; ++j) {
    for (int k = n / 2; k > (i ^= k); k /= 2)
      ;
    if (j < i) std::swap(res[i], res[j]);
  }
  return res;
}

std::vector<ll> convolution(const std::vector<ll> &lhs,
                            const std::vector<ll> &rhs) {
  int n = 1, a = lhs.size(), b = rhs.size();
  while (n < std::max(a, b) * 2) n <<= 1;
  std::vector<Point> ra(n), rb(n);
  for (int i = 0; i < n / 2; ++i) {
    if (i < a) ra[i] = Point(lhs[i], 0);
    if (i < b) rb[i] = Point(rhs[i], 0);
  }
  ra = FFT(ra, n);
  rb = FFT(rb, n);
  for (int i = 0; i < n; ++i) ra[i] *= rb[i];
  ra = FFT(ra, -n);
  std::vector<ll> res(n);
  for (int i = 0; i < n; ++i) res[i] = ra[i].real() / n + 0.5;
  return res;
}
