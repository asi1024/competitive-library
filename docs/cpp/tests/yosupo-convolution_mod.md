---
title: "yosupo-convolution_mod.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/tests/yosupo-convolution_mod.cpp)

{% highlight cpp %}
#include "../include/math/fmt.cpp"
#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"

using namespace std;

using Mod = Modulo<998244353, true>;

int main() {
  int n, m;
  fcin >> n >> m;
  std::vector<Mod> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    int x;
    fcin >> x;
    a[i] = Mod(x);
  }
  for (int i = 0; i < m; ++i) {
    int x;
    fcin >> x;
    b[i] = Mod(x);
  }
  std::vector<Mod> c = convolution<3>(a, b);
  for (int i = 0; i < n + m - 1; ++i) {
    fcout << int(c[i]) << (i == n + m - 2 ? "\n" : " ");
  }
  return 0;
}
{% endhighlight %}

### Includes

- [fmt.cpp](../include/math/fmt)
- [fast_cin.cpp](../include/others/fast_cin)
- [fast_cout.cpp](../include/others/fast_cout)

[Back](..)
