## fenwick_tree.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/fenwick_tree.cpp)

```cpp
template <typename T>
class FenwickTree {
  const int n;
  vector<T> data;
public:
  FenwickTree(int n) : n(n), data(n, 0) {}
  void add(int i, T value) {
    for (; i < n; i |= i + 1) data[i] += value;
  }
  T sum(int i) const {
    T res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) res += data[i];
    return res;
  }
  T sum(int l, int r) const { return sum(r - 1) - sum(l - 1); }
};
```

- [Back](../../../..)
