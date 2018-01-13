## mod.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/math/mod.cpp)

{% highlight cpp %}
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
  Modulo &operator+=(const Modulo &a) { n += a.n; if (n >= M) n -= M; return *this; }
  Modulo &operator-=(const Modulo &a) { n -= a.n; if (n < 0) n += M; return *this; }
  Modulo &operator*=(const Modulo &a) { n = (ll(n) * a.n) % M; return *this; }
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
  enable_if_t<IsPrime, Modulo> operator/=(const Modulo &a) {
    return *this *= inv(ll(a), M);
  }
};

const int mod = 1000000007;

template<int M = mod> Modulo<M, true> fact(int n, bool sw = true) {
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

template<int M = mod> Modulo<M, true> comb(int a, int b) {
  if (b < 0 || b > a) return 0;
  return fact<M>(a, true) * fact<M>(b, false) * fact<M>(a-b, false);
}

using Mod = Modulo<mod, true>;
{% endhighlight %}

[Back](../..)
