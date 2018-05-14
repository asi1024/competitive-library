{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/const_value.hpp)

{% highlight cpp %}
using ll = long long;
using ld = long double;

template<typename T> T inf;
template<> constexpr int inf<int> = 1e9;
template<> constexpr ll inf<ll> = 1e18;
template<> constexpr ld inf<ld> = 1e30;

template<typename T> T zero;
template<> constexpr int zero<int> = 0;
template<> constexpr ll zero<ll> = 0;
template<> constexpr ld zero<ld> = 0;
{% endhighlight %}

[Back](../..)
