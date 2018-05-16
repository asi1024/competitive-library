{% include mathjax.html %}

## inf

{% highlight cpp %}
T inf();
{% endhighlight %}

## inf< int >

{% highlight cpp %}
constexpr int inf< int >();
{% endhighlight %}

## inf< long long >

{% highlight cpp %}
constexpr long long inf< long long >();
{% endhighlight %}

## inf< long double >

{% highlight cpp %}
constexpr long double inf< long double >();
{% endhighlight %}

## zero

{% highlight cpp %}
T zero();
{% endhighlight %}

## zero< int >

{% highlight cpp %}
constexpr int zero< int >();
{% endhighlight %}

## zero< long long >

{% highlight cpp %}
constexpr long long zero< long long >();
{% endhighlight %}

## zero< long double >

{% highlight cpp %}
constexpr long double zero< long double >();
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/const_value.hpp)

{% highlight cpp %}
template<typename T> T inf();
template<> constexpr int inf<int>() { return 1e9; }
template<> constexpr long long inf<long long>() { return 1e18; }
template<> constexpr long double inf<long double>() { return 1e30; }

template<typename T> T zero();
template<> constexpr int zero<int>() { return 0; }
template<> constexpr long long zero<long long>() { return 0; }
template<> constexpr long double zero<long double>() { return 0; }
{% endhighlight %}

[Back](../..)
