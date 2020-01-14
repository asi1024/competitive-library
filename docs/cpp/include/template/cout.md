---
title: "cout.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/cout.cpp)

{% highlight cpp %}
#include "includes.cpp"

template <typename T, int M, int N> struct tuple_printer {
  static void print(std::ostream &os, const T &x) {
    os << std::get<M>(x) << " ";
    tuple_printer<T, M + 1, N>::print(os, x);
  }
};

template <typename T, int N> struct tuple_printer<T, N, N> {
  static void print(std::ostream &os, const T &x) { os << std::get<N>(x); }
};

template <typename... Args>
std::ostream &operator<<(std::ostream &os, const std::tuple<Args...> &t) {
  tuple_printer<std::tuple<Args...>, 0, sizeof...(Args) - 1>::print(os, t);
  return os;
}

template <typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &p) {
  os << p.first << " " << p.second;
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << " ";
    os << *it;
  }
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::set<T> &v) {
  for (auto it = v.begin(); it != v.end(); ++it) {
    if (it != v.begin()) os << " ";
    os << *it;
  }
  return os;
}
{% endhighlight %}

### Includes

- [includes.cpp](includes)

[Back](../..)
