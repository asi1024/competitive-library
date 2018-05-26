{% include mathjax.html %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
float_torelance(float_type value);
{% endhighlight %}


---------------------------------------

### [2] operator*
{% highlight cpp %}
operator*(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [3] operator*=
{% highlight cpp %}
operator*=(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [4] operator+
{% highlight cpp %}
operator+(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [5] operator+=
{% highlight cpp %}
operator+=(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [6] operator-
{% highlight cpp %}
operator-(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [7] operator-=
{% highlight cpp %}
operator-=(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [8] operator/
{% highlight cpp %}
operator/(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [9] operator/=
{% highlight cpp %}
operator/=(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [10] operator&lt;
{% highlight cpp %}
bool operator<(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [11] operator&lt;=
{% highlight cpp %}
bool operator<=(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [12] operator==
{% highlight cpp %}
bool operator==(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [13] operator&gt;
{% highlight cpp %}
bool operator>(const float_torelance &r);
{% endhighlight %}


---------------------------------------

### [14] operator&gt;=
{% highlight cpp %}
bool operator>=(const float_torelance &r);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/double.hpp)

{% highlight cpp %}
template <typename float_type, const float_type &eps> class float_torelance {
  float_type x;

public:
  float_torelance(float_type value) : x(value) { ; }
  float_torelance operator+(const float_torelance &r) { return x + r.x; }
  float_torelance operator-(const float_torelance &r) { return x - r.x; }
  float_torelance operator*(const float_torelance &r) { return x * r.x; }
  float_torelance operator/(const float_torelance &r) { return x / r.x; }
  float_torelance &operator+=(const float_torelance &r) { return x += r.x; }
  float_torelance &operator-=(const float_torelance &r) { return x -= r.x; }
  float_torelance &operator*=(const float_torelance &r) { return x *= r.x; }
  float_torelance &operator/=(const float_torelance &r) { return x /= r.x; }
  bool operator<=(const float_torelance &r) { return x <= r.x + eps; }
  bool operator<(const float_torelance &r) { return x < r.x - eps; }
  bool operator>=(const float_torelance &r) { return x >= r.x - eps; }
  bool operator>(const float_torelance &r) { return x > r.x + eps; }
  bool operator==(const float_torelance &r) {
    return x - r.x < eps && r.x - x < eps;
  }
};

constexpr long double epsilon11 = 1e-11;
using real = float_torelance<long double, epsilon11>;
{% endhighlight %}

[Back](../..)
