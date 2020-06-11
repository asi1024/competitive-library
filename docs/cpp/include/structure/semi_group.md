---
title: "semi_group.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/semi_group.cpp)

{% highlight cpp %}
#include "../template/includes.cpp"

template <typename T> struct RightHandSide {
  using value_type = T;
  static value_type op(const value_type &, const value_type &r) { return r; }
};
{% endhighlight %}

### Includes

- [includes.cpp](../template/includes)

[Back](../..)
