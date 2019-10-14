## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/cin.cpp)

{% highlight cpp %}
#include "includes.hpp"

template <typename T, int M, int N> struct tuple_getter {
  static void get(std::istream &is, T &x) {
    is >> std::get<M>(x);
    tuple_getter<T, M + 1, N>::get(is, x);
  }
};

template <typename T, int N> struct tuple_getter<T, N, N> {
  static void get(std::istream &is, T &x) { is >> std::get<N>(x); }
};

template <typename... Args>
std::istream &operator>>(std::istream &is, std::tuple<Args...> &t) {
  tuple_getter<std::tuple<Args...>, 0, sizeof...(Args) - 1>::get(is, t);
  return is;
}

template <typename T, typename U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
  for (T &x : v) is >> x;
  return is;
}
{% endhighlight %}

### Includes

- [includes.hpp](includes)

[Back](../..)
