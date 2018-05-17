{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/semi_group.hpp)

{% highlight cpp %}
#include "../template/includes.hpp"

template <typename T> struct RightHandSide {
  using value_type = T;
  static value_type op(const value_type &l, const value_type &r) { return r; }
};
{% endhighlight %}

### Includes

- [includes.hpp](../template/includes)

[Back](../..)
