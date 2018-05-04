## chmin

{% highlight cpp %}
T& chmin(T &a, const T &b);
{% endhighlight %}

## chmax

{% highlight cpp %}
T& chmax(T &a, const T &b);
{% endhighlight %}

## prime_factorization

{% highlight cpp %}
vector<pair<ll,int> > prime_factorization(ll n);
{% endhighlight %}

## init

{% highlight cpp %}
void init();
{% endhighlight %}

## comb

{% highlight cpp %}
Mod comb(int a, int b);
{% endhighlight %}

## FFT

{% highlight cpp %}
vector<P> FFT(ld theta, const vector< P > &a);
{% endhighlight %}

## convolution

{% highlight cpp %}
vector<ll> convolution(const vector< ll > &lhs, const vector< ll > &rhs);
{% endhighlight %}

## convolution

{% highlight cpp %}
vector<T> convolution(const vector< T > &lhs, const vector< T > &rhs);
{% endhighlight %}

## main

{% highlight cpp %}
int main();
{% endhighlight %}

## yes_no

### Member functions

- do_falsename
- do_truename

## Modulo

### Member functions

- (constructor)
- operator int
- operator ll
- operator*
- operator*=
- operator+
- operator+=
- operator-
- operator-=
- operator/
- operator/=
- operator==
- operator^

## Mod

### Member functions

- (constructor)
- operator Modulo
- operator ll
- operator*
- operator*=
- operator/
- operator/=
- operator^
- powi

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/math/mod_dynamic.cpp)

{% highlight cpp %}
/* -------------------------------- Template -------------------------------- */

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <locale>
#include <iostream>
#include <map>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;
using P = complex<ld>;

const ld pi = acos(-1.0);

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "YES"; }
  string_type do_falsename() const { return "NO"; }
};

/* -------------------------------- Library -------------------------------- */

vector<pair<ll,int>> prime_factorization(ll n) {
  vector<pair<ll,int>> res;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      res.emplace_back(i, 1); n /= i;
      while (n % i == 0) { ++res.back().second; n /= i; }
    }
  }
  res.emplace_back(n, 1);
  return res;
}

int mod;

class Modulo {
  int n;
public:
  Modulo () : n(0) {;}
  Modulo (int m) : n(m) {
    if (n >= mod) n %= mod;
    else if (n < 0) n = (n % mod + mod) % mod;
  }
  Modulo (ll m) {
    if (m >= mod) m %= mod;
    else if (m < 0) m = (m % mod + mod) % mod;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator ll() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo operator+=(const Modulo &a) { n += a.n; if (n >= mod) n -= mod; return *this; }
  Modulo operator-=(const Modulo &a) { n -= a.n; if (n < 0) n += mod; return *this; }
  Modulo operator*=(const Modulo &a) { n = (ll(n) * a.n) % mod; return *this; }
  Modulo operator+(const Modulo &a) const { Modulo res = *this; return res += a; }
  Modulo operator-(const Modulo &a) const { Modulo res = *this; return res -= a; }
  Modulo operator*(const Modulo &a) const { Modulo res = *this; return res *= a; }
  Modulo operator^(int n) const {
    if (n == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (n / 2);
    return n % 2 ? res * a : res;
  }
};

int len;
vector<ll> factor;

class Mod {
  Modulo n;
  vector<int> f;
  ll inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
  }
public:
  Mod (ll m) {
    assert (!factor.empty()); // assert
    f.assign(len, 0);
    for (int i = 0; i < len; ++i) {
      while (m % i == 0) {
        m /= factor[i];
        ++f[i];
      }
    }
    n = Modulo(m);
  }
  explicit operator Modulo() const {
    Modulo res = n;
    for (int i = 0; i < len; ++i) {
      res *= Modulo(factor[i]) ^ f[i];
    }
    return res;
  }
  explicit operator ll() const { return ll(Modulo(*this)); }
  Mod operator*=(const Mod &a) {
    n *= a.n;
    for (int i = 0; i < len; ++i) f[i] += a.f[i];
    return *this;
  }
  Mod operator/=(const Mod &a) {
    n *= inv(ll(a.n), mod);
    for (int i = 0; i < len; ++i) f[i] -= a.f[i];
    return *this;
  }
  Mod powi(int m) {
    n = n ^ m;
    for (int &i: f) i *= m;
    return *this;
  }
  Mod operator*(const Mod &a) const { Mod res = *this; return res *= a; }
  Mod operator/(const Mod &a) const { Mod res = *this; return res /= a; }
  Mod operator^(const int n) const { Mod res = *this; return res.powi(n); }
};

const int MAX_LEN = 1024000;

vector<Mod> fact;

void init() {
  assert (mod >= 2 && factor.empty());
  for (auto i: prime_factorization(mod)) {
    factor.push_back(i.first);
  }
  fact[0] = Mod(1);
  for (int i = 1; i < MAX_LEN; ++i) {
    fact.push_back(fact[i] * Mod(i));
  }
}

Mod comb(int a, int b) {
  if (b < 0 || b > a) return Mod(0);
  return fact[a] / (fact[b] * fact[a-b]);
}

// FFT
vector<P> FFT(ld theta, const vector<P> &a) {
  const int n = a.size();
  vector<P> ret = a;
  for (int m = n; m >= 2; m >>= 1, theta *= 2) {
    REP(i,m/2) {
      for (int j = i; j < n; j += m) {
        int k = j + m / 2;
        P x = ret[j] - ret[k];
        ret[j] += ret[k];
        ret[k] = exp(i * theta * P(0, 1)) * x;
      }
    }
  }
  for (int i = 0, j = 1; j < n - 1; j++) {
    for (int k = n >> 1; k > (i ^= k); k >>= 1) {;}
    if (j < i) swap(ret[i], ret[j]);
  }
  return ret;
}

vector<ll> convolution(const vector<ll> &lhs, const vector<ll> &rhs) {
  int n = 1, a = lhs.size(), b = rhs.size();
  while (n < max(a, b) * 2) n <<= 1;
  vector<P> temp1(n), temp2(n);
  REP(i,n/2) {
    if (i < a) temp1[i] = P(lhs[i], 0);
    if (i < b) temp2[i] = P(rhs[i], 0);
  }
  temp1 = FFT(2.0 * pi / n, temp1);
  temp2 = FFT(2.0 * pi / n, temp2);
  REP(i,n) temp1[i] *= temp2[i];
  temp1 = FFT(-2.0 * pi / n, temp1);
  vector<ll> ret(n);
  REP(i,n) ret[i] = temp1[i].real() / n + 0.5;
  return ret;
}

template <typename T>
vector<T> convolution(const vector<T> &lhs, const vector<T> &rhs) {
  const int base = 32000;
  const int n = lhs.size(), m = rhs.size();
  vector<ll> la(n), lb(n), l(n), ra(m), rb(m), r(m);
  for (int i = 0; i < n; ++i) {
    la[i] = ll(lhs[i]) / base;
    lb[i] = ll(lhs[i]) % base;
    l[i] = la[i] + lb[i];
  }
  for (int i = 0; i < m; ++i) {
    ra[i] = int(rhs[i]) / base;
    rb[i] = int(rhs[i]) / base;
    r[i] = ra[i] + rb[i];
  }
  vector<ll> a = convolution(la, ra);
  vector<ll> b = convolution(lb, rb);
  vector<ll> c = convolution(l, r);
  const int size = a.size();
  vector<T> res(size);
  for (int i = 0; i < size; ++i) {
    res[i] = T(a[i]) * T(base * base - base) -
      T(b[i]) * T(base - 1) + T(c[i]) * T(base);
  }
  return res;
}

/* ---------------------------------- Main ---------------------------------- */

int main() {
  int N, T;
  cin >> N >> T >> mod;
  init();
  vector<Modulo> a;
  a.reserve(T);
  return 0;
}
{% endhighlight %}

[Back](../..)
