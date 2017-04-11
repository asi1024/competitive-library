## unionfind.cpp

```
class UnionFind {
  vector<int> p;
public:
  UnionFind (int n) : p(n, -1) {}
  int root(int x) {
    return p[x] < 0 ? x : p[x] = root(p[x]);
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (p[y] < p[x]) swap(x, y);
    if (p[x] == p[y]) --p[x];
    p[y] = x;
    return true;
  }
};
```

- [Back](../)
