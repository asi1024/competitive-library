---
title: "semi_group.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/semi_group.cpp)

{% highlight cpp %}
#include "../template/includes.cpp"

template <typename T> struct LeftHandSide {
  using value_type = T;
  static value_type op(const value_type &l, const value_type &) { return l; }
};
{% endhighlight %}

### Includes

- [includes.cpp](../template/includes)

[Back](../..)
