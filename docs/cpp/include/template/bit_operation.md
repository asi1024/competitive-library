---
title: "bit_operation.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/bit_operation.cpp)

{% highlight cpp %}
int ctz(int n) {
  int res = 0;
  if ((n & 0x0000ffff) == 0) n >>= 16, res += 16;
  if ((n & 0x000000ff) == 0) n >>= 8, res += 8;
  if ((n & 0x0000000f) == 0) n >>= 4, res += 4;
  if ((n & 0x00000003) == 0) n >>= 2, res += 2;
  if ((n & 0x00000001) == 0) n >>= 1, res += 1;
  return res;
}

int lg(int n) {
  int res = 1;
  --n;
  if (n >> 16) n >>= 16, res += 16;
  if (n >> 8) n >>= 8, res += 8;
  if (n >> 4) n >>= 4, res += 4;
  if (n >> 2) n >>= 2, res += 2;
  if (n >> 1) n >>= 1, res += 1;
  return res;
}

int lg(long long n) {
  int res = 1;
  --n;
  if (n >> 32) n >>= 32, res += 32;
  if (n >> 16) n >>= 16, res += 16;
  if (n >> 8) n >>= 8, res += 8;
  if (n >> 4) n >>= 4, res += 4;
  if (n >> 2) n >>= 2, res += 2;
  if (n >> 1) n >>= 1, res += 1;
  return res;
}

template <typename T> int log2ceil(T n) { return T(1) << lg(n); }
{% endhighlight %}

[Back](../..)
