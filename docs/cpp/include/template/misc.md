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
#include "includes.hpp"

template <typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = std::max(a, b); }
{% endhighlight %}

### Includes

- [includes.hpp](includes)

[Back](../..)
