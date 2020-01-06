---
title: "eratosthenes.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/math/eratosthenes.cpp)

{% highlight cpp %}
#include "../template/includes.cpp"

std::vector<int> eratosthenes(int M) {
  std::vector<int> res(M, 0);
  res[0] = -1;
  res[1] = -1;
  for (int i = 2; i * i < M; ++i) {
    if (res[i] == 0) {
      for (int j = i * i; j < M; j += i) {
        if (res[j] == 0) res[j] = i;
      }
    }
  }
  return res;
}
{% endhighlight %}

### Includes

- [includes.cpp](../template/includes)

[Back](../..)
