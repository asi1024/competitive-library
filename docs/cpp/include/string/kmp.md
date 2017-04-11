## kmp.cpp

```
struct KMP {
  const int n;
  const string s;
  vector<int> f;
  KMP (const string &str) : n(str.size()), s(str), f(n, 0) {
    int k = 0;
    for (int i = 1; i < n; ++i) {
      while (k > 0 && s[k] != s[i]) k = f[k-1];
      if (s[k] == s[i]) ++k;
      f[i] = k;
    }
  }
  vector<int> query(const string &t) {
    int k = 0;
    vector<int> res;
    for (int i = 0; i < (int)t.size(); ++i) {
      while (k == n || (k > 0 && s[k] != t[i])) k = f[k-1];
      if (s[k] == t[i]) ++k;
      res.push_back(k);
    }
    return res;
  }
};
```

- [Back](../)
