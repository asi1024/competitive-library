{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/const_value.hpp)

{% highlight cpp %}
template<typename T> T inf;
template<> constexpr int inf<int> = 1e9;
template<> constexpr long long inf<long long> = 1e18;
template<> constexpr long double inf<long double> = 1e30;

template<typename T> T zero;
template<> constexpr int zero<int> = 0;
template<> constexpr long long zero<long long> = 0;
template<> constexpr long double zero<long double> = 0;
{% endhighlight %}

[Back](../..)
