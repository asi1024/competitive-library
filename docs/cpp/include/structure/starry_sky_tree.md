## starry_sky_tree.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/starry_sky_tree.cpp)

```cpp
// 非再帰で書き直そうとしたらバグった
// バグってるから使わないでね

template <typename T>
class StarrySkyTree {
  const int n;
  vector<T> data, lazy;
  int expand(int n) const { return n == 1 ? n : expand((n + 1) / 2) * 2; }
public:
  StarrySkyTree(int m) : n(expand(m)), data(n * 2, 0), lazy(n * 2, 0) {}
  void add(int l, int r, T val) {
    l += n; r += n;
    const int left = l, right = r;
    while (l != r) {
      if (l % 2) { lazy[l] += val; data[l++] += val; }
      if (r % 2) { lazy[--r] += val; data[r] += val; }
      l /= 2; r /= 2;
    }
    l = left; r = right - 1;
    while (l /= 2, r /= 2) {
      data[l] = min(data[l * 2], data[l * 2 + 1]);
      data[r] = min(data[r * 2], data[r * 2 + 1]);
    }
  }
  T minimum(int l, int r) const {
    l += n; r += n;
    T res1 = inf<T>, res2 = inf<T>;
    int left = l, right = r;
    while (l != r) {
      res1 += lazy[left];
      res2 += lazy[--right];
      if (l % 2) res1 = min(res1, data[l++]);
      if (r % 2) res2 = min(res2, data[--r]);
      l /= 2; r /= 2; left /= 2; right /= 2;
    }
    while (left) {
      res1 += lazy[left];
      res2 += lazy[--right];
      left /= 2; right /= 2;
    }
    return min(min(res1, res2), inf<T>);
  }
};

// Verified : Codeforces 52C (Circular RMQ)
/*
char str[2048000];

vector<int> get_int() {
  fgets(str, 2048000, stdin);
  vector<int> res;
  int n = 0;
  bool flag = false;
  for (int i = 0;; ++i) {
    if (str[i] == '-') { flag = true; ++i; }
    if (str[i] == ' ' || str[i] == '\n') {
      if (flag) n = -n;
      res.push_back(n); n = 0; flag = false;
    }
    else {
      n = n * 10 + (int)(str[i] - '0');
    }
    if (str[i] == '\n') break;
  }
  return res;
}

using ll = long long;

int main() {
  int N = get_int()[0];
  StarrySkyTree<ll> seg(N);
  vector<int> a = get_int();
  for (int i = 0; i < N; ++i) seg.add(i, i+1, a[i]);
  int Q = get_int()[0];
  while (Q--) {
    vector<int> com = get_int();
    int l = com[0], r = com[1];
    if (com.size() == 2) {
      if (l > r) cout << min(seg.minimum(l, N), seg.minimum(0, r+1)) << endl;
      else cout << seg.minimum(l, r+1) << endl;
    }
    else {
      ll v = com[2];
      if (l > r) { seg.add(l, N, v); seg.add(0, r+1, v); }
      else seg.add(l, r+1, v);
    }
  }
  return 0;
}
*/
```

- [Back](https://{{ site.github.owner_name }}.github.io/competitive-library)
