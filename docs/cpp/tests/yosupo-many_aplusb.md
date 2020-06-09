---
title: "yosupo-many_aplusb.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/yosupo-many_aplusb.cpp)

{% highlight cpp %}
#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"

int main() {
  int T;
  long long x, y;
  fcin >> T;
  while (T--) {
    fcin >> x >> y;
    fcout << x + y << fendl;
  }
  return 0;
}
{% endhighlight %}

### Includes

- [fast_cin.cpp](../include/others/fast_cin)
- [fast_cout.cpp](../include/others/fast_cout)

[Back](..)
