---
title: "misc.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/misc.cpp)

{% highlight cpp %}
#include "includes.cpp"

template <typename T> T &chmin(T &a, const T &b) { return a = std::min(a, b); }

template <typename T> T &chmax(T &a, const T &b) { return a = std::max(a, b); }
{% endhighlight %}

### Includes

- [includes.cpp](includes)

[Back](../..)
