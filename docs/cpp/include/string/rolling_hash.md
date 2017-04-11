## rolling_hash.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/string/rolling_hash.cpp)

```cpp
class RollingHash {
  using ll = long long;
  const int n;
  static const ll moda = 1000000000000037LL;
  static const ll modb = 1000000000000091LL;
  static const ll pa = 17LL;
  static const ll pb = 19LL;
  vector<ll> a, b, p, q;
public:
  RollingHash (const string &str) :
    n(str.size()), a(n+1, 0), b(n+1, 0), p(n+1, 1), q(n+1, 1) {
    for (int i = 0; i < n; ++i) {
      a[i+1] = (a[i] * pa + str[i]) % moda;
      b[i+1] = (b[i] * pb + str[i]) % modb;
      p[i+1] = p[i] * pa % moda;
      q[i+1] = q[i] * pb % modb;
    }
  }
  pair<ll,ll> query(int l, int r) {
    return make_pair(((__int128)p[r - l] * a[l] - a[r] + moda) % moda,
                     ((__int128)q[r - l] * b[l] - b[r] + modb) % modb);
  }
};
```

- [Back](https://{{ site.github.owner_name }}.github.io/competitive-library)
