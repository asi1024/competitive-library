## FMT

{% highlight cpp %}
void FMT(vector< Modulo< mod, true >> &a);
{% endhighlight %}

## convolution

{% highlight cpp %}
vector<Modulo<mod, true> > convolution(vector< Modulo< mod, true >> a, vector< Modulo< mod, true >> b);
{% endhighlight %}

### Includes

- [mod.cpp](mod)

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/math/fmt.cpp)

{% highlight cpp %}
#include "mod.cpp"

template<int prim_root, int mod, int sign>
void FMT(vector<Modulo<mod, true>> &a) {
  using mod_t = Modulo<mod, true>;
  const int n = a.size();
  mod_t h = mod_t(prim_root) ^ ((mod - 1) / n);
  if (sign == -1) h = mod_t(1) / h;
  int x = 0;
  for (int i = 1; i < n - 1; ++i) {
    for (int j = n / 2; j > (x ^= j); j /= 2);
    if (i < x) swap(a[x], a[i]);
  }
  for (int m = 1; m < n; m *= 2) {
    const int m2 = 2 * m;
    const mod_t base = mod_t(h) ^ (n / m2);
    mod_t w = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = i; j < n; j += m2) {
        const mod_t u = a[j], d = a[j + m] * w;
        a[j] = u + d;
        a[j + m] = u - d;
      }
      w *= base;
    }
  }
}

template<int prim_root, int mod>
vector<Modulo<mod, true>> convolution(vector<Modulo<mod, true>> a,
                                      vector<Modulo<mod, true>> b) {
  using mod_t = Modulo<mod, true>;
  int size = a.size() + b.size();
  while ((size & -size) != size) size += (size & -size);
  a.resize(size); FMT<prim_root, mod, 1>(a);
  b.resize(size); FMT<prim_root, mod, 1>(b);
  for (int i = 0; i < size; ++i) a[i] *= b[i];
  FMT<prim_root, mod, -1>(a);
  const mod_t inv = mod_t(1) / mod_t(size);
  for (auto &x : a) x *= inv;
  return a;
}
{% endhighlight %}

[Back](../..)
