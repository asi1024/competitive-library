{% include mathjax.html %}

## inf

{% highlight cpp %}
constexpr T inf();
{% endhighlight %}

## inf&lt; int &gt;

{% highlight cpp %}
constexpr int inf< int >();
{% endhighlight %}

## inf&lt; long long &gt;

{% highlight cpp %}
constexpr long long inf< long long >();
{% endhighlight %}

## inf&lt; long double &gt;

{% highlight cpp %}
constexpr long double inf< long double >();
{% endhighlight %}

## zero

{% highlight cpp %}
constexpr std::enable_if<std::is_arithmetic<T>::value, T>::type zero();
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/const_value.hpp)

{% highlight cpp %}
#include "includes.hpp"


template <typename T> constexpr T inf();
template <> constexpr int inf<int>() { return 1e9; }
template <> constexpr long long inf<long long>() { return 1e18; }
template <> constexpr long double inf<long double>() { return 1e30; }

template <typename T>
constexpr typename std::enable_if<std::is_arithmetic<T>::value, T>::type
zero() {
  return T(0);
}

const long double pi = acos(-1.0);
{% endhighlight %}

### Includes

- [includes.hpp](includes)

[Back](../..)
