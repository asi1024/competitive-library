{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/monoid.hpp)

{% highlight cpp %}
#include "../template/includes.hpp"

struct RMQ {
  using value_type = int;
  static value_type id() { return INT_MAX; }
  static value_type op(const value_type &l, const value_type &r) {
    return std::min(l, r);
  }
};
{% endhighlight %}

### Includes

- [includes.hpp](../template/includes)

[Back](../..)
