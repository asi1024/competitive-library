---
title: "fft.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/math/fft.cpp)

{% highlight cpp %}
#include "../template/includes.hpp"
#include "../template/typedef.hpp"

namespace {
using complex = std::complex<ld>;
std::vector<complex> FFT(const std::vector<complex> &a, int n) {
  ld theta = 2.0 * pi / n;
  const int len = a.size();
  std::vector<complex> res = a;
  for (int m = len; m >= 2; m /= 2, theta *= 2) {
    for (int i = 0; i < m / 2; ++i) {
      for (int j = i; j < len; j += m) {
        int k = j + m / 2;
        complex x = res[j] - res[k];
        res[j] += res[k];
        res[k] = exp(i * theta * complex(0, 1)) * x;
      }
    }
  }
  for (int i = 0, j = 1; j < len - 1; ++j) {
    for (int k = len / 2; k > (i ^= k); k /= 2)
      ;
    if (j < i) std::swap(res[i], res[j]);
  }
  return res;
}
}  // namespace

std::vector<ll> convolution(const std::vector<ll> &lhs,
                            const std::vector<ll> &rhs) {
  int n = 1, a = lhs.size(), b = rhs.size();
  while (n < std::max(a, b) * 2) n <<= 1;
  std::vector<std::complex<ld>> ra(n), rb(n);
  for (int i = 0; i < n / 2; ++i) {
    if (i < a) ra[i] = std::complex<ld>(lhs[i], 0);
    if (i < b) rb[i] = std::complex<ld>(rhs[i], 0);
  }
  ra = FFT(ra, n);
  rb = FFT(rb, n);
  for (int i = 0; i < n; ++i) ra[i] *= rb[i];
  ra = FFT(ra, -n);
  std::vector<ll> res(n);
  for (int i = 0; i < n; ++i) res[i] = ra[i].real() / n + 0.5;
  return res;
}
{% endhighlight %}

### Includes

- [includes.hpp](../template/includes)
- [typedef.hpp](../template/typedef)

[Back](../..)
