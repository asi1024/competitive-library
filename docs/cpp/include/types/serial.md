---
title: "serial.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/types/serial.cpp)

{% highlight cpp %}
#include "../template/includes.cpp"

class Serial {
  static int count;
  int num;

public:
  Serial() : num(count) {
    assert(count >= 0);
    ++count;
  }
  Serial(const Serial &) = delete;
  Serial(Serial &&other) { num = other.num; }
  static void reset() { count = 0; }
  static int size() { return count; }
  operator int() const { return num; }
};

int Serial::count = -1;
{% endhighlight %}

### Includes

- [includes.cpp](../template/includes)

[Back](../..)
