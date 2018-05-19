{% include mathjax.html %}

## FFT

{% highlight cpp %}
vector<P> FFT(const vector< P > &a, int m);
{% endhighlight %}

## convolution

{% highlight cpp %}
vector<ll> convolution(const vector< ll > &lhs, const vector< ll > &rhs);
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/math/fft.cpp)

{% highlight cpp %}
#include "../util.hpp"

typedef long long ll;

using ld = long double;
using P = complex<ld>;

const ld pi = acos(-1.0);

vector<P> FFT(const vector<P> &a, int m) {
  ld theta = 2.0 * pi / m;
  const int n = a.size();
  vector<P> res = a;
  for (int m = n; m >= 2; m /= 2, theta *= 2) {
    for (int i = 0; i < m / 2; ++i) {
      for (int j = i; j < n; j += m) {
        int k = j + m / 2;
        P x = res[j] - res[k];
        res[j] += res[k];
        res[k] = exp(i * theta * P(0, 1)) * x;
      }
    }
  }
  for (int i = 0, j = 1; j < n - 1; ++j) {
    for (int k = n / 2; k > (i ^= k); k /= 2)
      ;
    if (j < i) swap(res[i], res[j]);
  }
  return res;
}

vector<ll> convolution(const vector<ll> &lhs, const vector<ll> &rhs) {
  int n = 1, a = lhs.size(), b = rhs.size();
  while (n < max(a, b) * 2) n <<= 1;
  vector<P> ra(n), rb(n);
  for (int i = 0; i < n / 2; ++i) {
    if (i < a) ra[i] = P(lhs[i], 0);
    if (i < b) rb[i] = P(rhs[i], 0);
  }
  ra = FFT(ra, n);
  rb = FFT(rb, n);
  for (int i = 0; i < n; ++i) ra[i] *= rb[i];
  ra = FFT(ra, -n);
  vector<ll> res(n);
  for (int i = 0; i < n; ++i) res[i] = ra[i].real() / n + 0.5;
  return res;
}
{% endhighlight %}

### Includes

- [util.hpp](../util)

[Back](../..)
