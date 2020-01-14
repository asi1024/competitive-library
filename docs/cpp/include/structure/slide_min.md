---
title: "slide_min.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/slide_min.cpp)

{% highlight cpp %}
#include "../template/includes.cpp"

template <typename T> struct SlideMin {
  std::deque<std::pair<int, T>> deq;
  int l, r;
  SlideMin() : l(0), r(0) { ; }
  void push(T val) {
    while (!deq.empty() && deq.back().second >= val) deq.pop_back();
    deq.emplace_back(r, val);
    ++r;
  }
  void pop() {
    assert(!deq.empty());
    if (deq.front().first <= l) deq.pop_front();
    ++l;
  }
  int size() const { return r - l; }
  T minimum() const { return deq.front().second; }
};
{% endhighlight %}

### Includes

- [includes.cpp](../template/includes)

[Back](../..)
