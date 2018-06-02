{% include mathjax.html %}

## table

{% highlight cpp %}
std::vector<T> table(int n, T v);
{% endhighlight %}

## table

{% highlight cpp %}
auto table(int n, Args... args);
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/table.hpp)

{% highlight cpp %}
#include "includes.hpp"

template <typename T> std::vector<T> table(int n, T v) {
  return vector<T>(n, v);
}

template <class... Args> auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}
{% endhighlight %}

### Includes

- [includes.hpp](includes)

[Back](../..)
