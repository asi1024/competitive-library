---
title: "yosupo-static_range_sum.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/yosupo-static_range_sum.cpp)

{% highlight cpp %}
#include <numeric>

#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"

long long sum[512000];

int main() {
  int N, Q;
  fcin >> N >> Q;
  for (int i = 0; i < N; ++i) fcin >> sum[i + 1];
  std::partial_sum(sum + 1, sum + N + 1, sum + 1);
  while (Q--) {
    int l, r;
    fcin >> l >> r;
    fcout << sum[r] - sum[l] << fendl;
  }
  return 0;
}
{% endhighlight %}

### Includes

- [fast_cin.cpp](../include/others/fast_cin)
- [fast_cout.cpp](../include/others/fast_cout)

[Back](..)
