## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/const_value.hpp)

{% highlight cpp %}
#include "includes.hpp"


namespace sub {
template <typename T>
constexpr typename std::enable_if<std::is_integral<T>::value, T>::type
inf_sub() {
  return std::numeric_limits<T>::max() / 2 - 1000;
}

template <typename T>
constexpr typename std::enable_if<std::is_floating_point<T>::value, T>::type
inf_sub() {
  return std::min(std::numeric_limits<T>::max() / 2 - 1000, T(1e50));
}
}  // namespace sub

template <typename T> constexpr T inf() {
  static_assert(std::is_arithmetic<T>::value, "T must be arithmetic value");
  return sub::inf_sub<T>();
}

template <typename T> constexpr T zero() {
  static_assert(std::is_arithmetic<T>::value, "T must be arithmetic value");
  return T(0);
}

const long double pi = acos(-1.0);
{% endhighlight %}

### Includes

- [includes.hpp](includes)

[Back](../..)
