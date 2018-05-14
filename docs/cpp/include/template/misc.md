{% include mathjax.html %}

## chmin

{% highlight cpp %}
T& chmin(T &a, const T &b);
{% endhighlight %}

## chmax

{% highlight cpp %}
T& chmax(T &a, const T &b);
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/misc.hpp)

{% highlight cpp %}
template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
{% endhighlight %}

[Back](../..)
