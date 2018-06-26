{% include mathjax.html %}

## is_zero

{% highlight cpp %}
bool is_zero(Modulo< M, IsPrime > x);
{% endhighlight %}

## abs

{% highlight cpp %}
int abs(Modulo< M, IsPrime > x);
{% endhighlight %}

## fact

{% highlight cpp %}
Modulo<M, true> fact(int n, bool sw=true);
{% endhighlight %}

## comb

{% highlight cpp %}
Modulo<M, true> comb(int a, int b);
{% endhighlight %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
Modulo();
Modulo(int m);
Modulo(ll m);
{% endhighlight %}


---------------------------------------

### [2] operator int
{% highlight cpp %}
operator int() const;
{% endhighlight %}


---------------------------------------

### [3] operator ll
{% highlight cpp %}
operator ll() const;
{% endhighlight %}


---------------------------------------

### [4] operator*
{% highlight cpp %}
operator*(const Modulo &a) const;
{% endhighlight %}


---------------------------------------

### [5] operator*=
{% highlight cpp %}
operator*=(const Modulo &a);
{% endhighlight %}


---------------------------------------

### [6] operator+
{% highlight cpp %}
operator+(const Modulo &a) const;
{% endhighlight %}


---------------------------------------

### [7] operator+=
{% highlight cpp %}
operator+=(const Modulo &a);
{% endhighlight %}


---------------------------------------

### [8] operator-
{% highlight cpp %}
operator-(const Modulo &a) const;
{% endhighlight %}


---------------------------------------

### [9] operator-=
{% highlight cpp %}
operator-=(const Modulo &a);
{% endhighlight %}


---------------------------------------

### [10] operator/
{% highlight cpp %}
std::enable_if< IsPrime, operator/(const Modulo &a) const;
{% endhighlight %}


---------------------------------------

### [11] operator/=
{% highlight cpp %}
std::enable_if< IsPrime, operator/=(const Modulo &a);
{% endhighlight %}


---------------------------------------

### [12] operator==
{% highlight cpp %}
bool operator==(const Modulo &a) const;
{% endhighlight %}


---------------------------------------

### [13] operator^
{% highlight cpp %}
operator^(int m) const;
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/types/mod.cpp)

{% highlight cpp %}
#include "../template/includes.hpp"
#include "../template/typedef.hpp"

template <int M, bool IsPrime = false> class Modulo {
  int n;
  static typename std::enable_if<IsPrime, ll>::type inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
  }

public:
  Modulo() : n(0) { ; }
  Modulo(int m) : n(m) {
    if (n >= M)
      n %= M;
    else if (n < 0)
      n = (n % M + M) % M;
  }
  Modulo(ll m) {
    if (m >= M)
      m %= M;
    else if (m < 0)
      m = (m % M + M) % M;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator ll() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo &operator+=(const Modulo &a) {
    n += a.n;
    if (n >= M) n -= M;
    return *this;
  }
  Modulo &operator-=(const Modulo &a) {
    n -= a.n;
    if (n < 0) n += M;
    return *this;
  }
  Modulo &operator*=(const Modulo &a) {
    n = (ll(n) * a.n) % M;
    return *this;
  }
  Modulo operator+(const Modulo &a) const {
    Modulo res = *this;
    return res += a;
  }
  Modulo operator-(const Modulo &a) const {
    Modulo res = *this;
    return res -= a;
  }
  Modulo operator*(const Modulo &a) const {
    Modulo res = *this;
    return res *= a;
  }
  Modulo operator^(int m) const {
    if (m == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (m / 2);
    return m % 2 ? res * a : res;
  }
  typename std::enable_if<IsPrime, Modulo>::type
  operator/(const Modulo &a) const {
    return *this * inv(ll(a), M);
  }
  typename std::enable_if<IsPrime, Modulo>::type operator/=(const Modulo &a) {
    return *this *= inv(ll(a), M);
  }
};

template <int M, bool IsPrime = false> bool is_zero(Modulo<M, IsPrime> x) {
  return int(x) == 0;
}
template <int M, bool IsPrime = false> int abs(Modulo<M, IsPrime> x) {
  return int(x);
}

const int mod = 1000000007;

template <int M = mod> Modulo<M, true> fact(int n, bool sw = true) {
  static std::vector<Modulo<M, true>> v1 = { 1 }, v2 = { 1 };
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

template <int M = mod> Modulo<M, true> comb(int a, int b) {
  if (b < 0 || b > a) return 0;
  return fact<M>(a, true) * fact<M>(b, false) * fact<M>(a - b, false);
}

using Mod = Modulo<mod, true>;
{% endhighlight %}

### Includes

- [includes.hpp](../template/includes)
- [typedef.hpp](../template/typedef)

[Back](../..)