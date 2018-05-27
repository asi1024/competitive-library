{% include mathjax.html %}

## operator&gt;&gt;

{% highlight cpp %}
std::istream& operator>>(std::istream &is, float_torelance< float_type, eps > &x);
{% endhighlight %}

## operator&lt;&lt;

{% highlight cpp %}
std::ostream& operator<<(std::ostream &os, const float_torelance< float_type, eps > &x);
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

template <typename float_type, const float_type &eps> class float_torelance {
public:
  float_type x;
  float_torelance() { ; }
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

namespace std {
template <typename float_type, const float_type &eps>
float_torelance<float_type, eps> abs(float_torelance<float_type, eps> &x) {
  return float_torelance<float_type, eps>(std::abs(x.x));
}

template <typename float_type, const float_type &eps>
float_torelance<float_type, eps>
sqrt(const float_torelance<float_type, eps> &x) {
  return float_torelance<float_type, eps>(std::sqrt(x.x));
}
}

template <typename float_type, const float_type &eps>
std::istream &operator>>(std::istream &is,
                         float_torelance<float_type, eps> &x) {
  is >> x.x;
  return is;
}

template <typename float_type, const float_type &eps>
std::ostream &operator<<(std::ostream &os,
                         const float_torelance<float_type, eps> &x) {
  os << x.x;
  return os;
}

constexpr long double epsilon11 = 1e-11;
using float11 = float_torelance<long double, epsilon11>;
{% endhighlight %}

### Includes

- [includes.hpp](includes)

[Back](../..)
