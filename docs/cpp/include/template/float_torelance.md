{% include mathjax.html %}

## abs

{% highlight cpp %}
float_torelance<float_type, inv_eps> abs(const float_torelance< float_type, inv_eps > &x);
{% endhighlight %}

## atan2

{% highlight cpp %}
float_torelance<float_type, inv_eps> atan2(const float_torelance< float_type, inv_eps > &x, const float_torelance< float_type, inv_eps > &y);
{% endhighlight %}

## copysign

{% highlight cpp %}
bool copysign(const float_torelance< float_type, inv_eps > &x, const float_torelance< float_type, inv_eps > &y);
{% endhighlight %}

## isinf

{% highlight cpp %}
bool isinf(const float_torelance< float_type, inv_eps > &x);
{% endhighlight %}

## isnan

{% highlight cpp %}
bool isnan(const float_torelance< float_type, inv_eps > &x);
{% endhighlight %}

## sqrt

{% highlight cpp %}
float_torelance<float_type, inv_eps> sqrt(const float_torelance< float_type, inv_eps > &x);
{% endhighlight %}

## operator&gt;&gt;

{% highlight cpp %}
std::istream& operator>>(std::istream &is, float_torelance< float_type, inv_eps > &x);
{% endhighlight %}

## operator&lt;&lt;

{% highlight cpp %}
std::ostream& operator<<(std::ostream &os, const float_torelance< float_type, inv_eps > &x);
{% endhighlight %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
float_torelance();
float_torelance(float_type x_);
{% endhighlight %}


---------------------------------------

### [2] operator float_type
{% highlight cpp %}
operator float_type();
{% endhighlight %}


---------------------------------------

### [3] operator!=
{% highlight cpp %}
bool operator!=(const float_torelance &r) const;
bool operator!=(const float_type &r) const;
{% endhighlight %}


---------------------------------------

### [4] operator*
{% highlight cpp %}
operator*(const float_torelance &r) const;
operator*(const float_type &r) const;
{% endhighlight %}


---------------------------------------

### [5] operator*=
{% highlight cpp %}
operator*=(const float_torelance &r);
operator*=(const float_type &r);
{% endhighlight %}


---------------------------------------

### [6] operator+
{% highlight cpp %}
operator+(const float_torelance &r) const;
operator+(const float_type &r) const;
{% endhighlight %}


---------------------------------------

### [7] operator+=
{% highlight cpp %}
operator+=(const float_torelance &r);
operator+=(const float_type &r);
{% endhighlight %}


---------------------------------------

### [8] operator-
{% highlight cpp %}
operator-() const;
operator-(const float_torelance &r) const;
operator-(const float_type &r) const;
{% endhighlight %}


---------------------------------------

### [9] operator-=
{% highlight cpp %}
operator-=(const float_torelance &r);
operator-=(const float_type &r);
{% endhighlight %}


---------------------------------------

### [10] operator/
{% highlight cpp %}
operator/(const float_torelance &r) const;
operator/(const float_type &r) const;
{% endhighlight %}


---------------------------------------

### [11] operator/=
{% highlight cpp %}
operator/=(const float_torelance &r);
operator/=(const float_type &r);
{% endhighlight %}


---------------------------------------

### [12] operator&lt;
{% highlight cpp %}
bool operator<(const float_torelance &r) const;
bool operator<(const float_type &r) const;
{% endhighlight %}


---------------------------------------

### [13] operator&lt;=
{% highlight cpp %}
bool operator<=(const float_torelance &r) const;
bool operator<=(const float_type &r) const;
{% endhighlight %}


---------------------------------------

### [14] operator==
{% highlight cpp %}
bool operator==(const float_torelance &r) const;
bool operator==(const float_type &r) const;
{% endhighlight %}


---------------------------------------

### [15] operator&gt;
{% highlight cpp %}
bool operator>(const float_torelance &r) const;
bool operator>(const float_type &r) const;
{% endhighlight %}


---------------------------------------

### [16] operator&gt;=
{% highlight cpp %}
bool operator>=(const float_torelance &r) const;
bool operator>=(const float_type &r) const;
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/float_torelance.hpp)

{% highlight cpp %}
#include "includes.hpp"

template <typename float_type, const long long inv_eps> class float_torelance {
public:
  static constexpr float_type eps = float_type(1) / inv_eps;
  float_type x;
  float_torelance() : x(0) { ; }
  float_torelance(float_type x_) : x(x_) { ; }
  explicit operator float_type() { return x; }
  float_torelance operator-() const { return -x; }
  float_torelance operator+(const float_torelance &r) const { return x + r.x; }
  float_torelance operator-(const float_torelance &r) const { return x - r.x; }
  float_torelance operator*(const float_torelance &r) const { return x * r.x; }
  float_torelance operator/(const float_torelance &r) const { return x / r.x; }
  float_torelance &operator+=(const float_torelance &r) {
    x += r.x;
    return *this;
  }
  float_torelance &operator-=(const float_torelance &r) {
    x -= r.x;
    return *this;
  }
  float_torelance &operator*=(const float_torelance &r) {
    x *= r.x;
    return *this;
  }
  float_torelance &operator/=(const float_torelance &r) {
    x /= r.x;
    return *this;
  }
  bool operator<=(const float_torelance &r) const { return x <= r.x + eps; }
  bool operator<(const float_torelance &r) const { return x < r.x - eps; }
  bool operator>=(const float_torelance &r) const { return x >= r.x - eps; }
  bool operator>(const float_torelance &r) const { return x > r.x + eps; }
  bool operator==(const float_torelance &r) const {
    return x - r.x < eps && r.x - x < eps;
  }
  bool operator!=(const float_torelance &r) const {
    return x - r.x > eps || r.x - x > eps;
  }

  float_torelance operator+(const float_type &r) const { return x + r; }
  float_torelance operator-(const float_type &r) const { return x - r; }
  float_torelance operator*(const float_type &r) const { return x * r; }
  float_torelance operator/(const float_type &r) const { return x / r; }
  float_torelance &operator+=(const float_type &r) {
    x += r;
    return *this;
  }
  float_torelance &operator-=(const float_type &r) {
    x -= r;
    return *this;
  }
  float_torelance &operator*=(const float_type &r) {
    x *= r;
    return *this;
  }
  float_torelance &operator/=(const float_type &r) {
    x /= r;
    return *this;
  }
  bool operator<=(const float_type &r) const { return x <= r + eps; }
  bool operator<(const float_type &r) const { return x < r - eps; }
  bool operator>=(const float_type &r) const { return x >= r - eps; }
  bool operator>(const float_type &r) const { return x > r + eps; }
  bool operator==(const float_type &r) const {
    return x - r < eps && r - x < eps;
  }
  bool operator!=(const float_type &r) const {
    return x - r > eps || r - x > eps;
  }
};

template <typename float_type, const long long inv_eps>
float_torelance<float_type, inv_eps>
abs(const float_torelance<float_type, inv_eps> &x) {
  return float_torelance<float_type, inv_eps>(std::abs(x.x));
}

template <typename float_type, const long long inv_eps>
float_torelance<float_type, inv_eps>
atan2(const float_torelance<float_type, inv_eps> &x,
      const float_torelance<float_type, inv_eps> &y) {
  return float_torelance<float_type, inv_eps>(std::atan2(x.x, y.x));
}

template <typename float_type, const long long inv_eps>
bool copysign(const float_torelance<float_type, inv_eps> &x,
              const float_torelance<float_type, inv_eps> &y) {
  return std::copysign(x.x, y.x);
}

template <typename float_type, const long long inv_eps>
bool isinf(const float_torelance<float_type, inv_eps> &x) {
  return std::isinf(x.x);
}

template <typename float_type, const long long inv_eps>
bool isnan(const float_torelance<float_type, inv_eps> &x) {
  return std::isnan(x.x);
}

template <typename float_type, const long long inv_eps>
float_torelance<float_type, inv_eps>
sqrt(const float_torelance<float_type, inv_eps> &x) {
  return float_torelance<float_type, inv_eps>(std::sqrt(x.x));
}

template <typename float_type, const long long inv_eps>
std::istream &operator>>(std::istream &is,
                         float_torelance<float_type, inv_eps> &x) {
  is >> x.x;
  return is;
}

template <typename float_type, const long long inv_eps>
std::ostream &operator<<(std::ostream &os,
                         const float_torelance<float_type, inv_eps> &x) {
  os << x.x;
  return os;
}

using float11 = float_torelance<long double, 100000000000LL>;
{% endhighlight %}

### Includes

- [includes.hpp](includes)

[Back](../..)
