## suffix_array.cpp

```
struct SuffixArray {
  struct SAComp {
    const int h;
    const vector<int> &g;
    SAComp(int h, vector<int> &g) : h(h), g(g) {;}
    bool operator() (int a, int b) {
      return a != b && (g[a] != g[b] ? g[a] < g[b] : g[a + h] < g[b + h]);
    }
  };

  int n;
  char *str;
  vector<int> sa, lcp;

  SuffixArray(const string &t) : n(t.size()), sa(n+1), lcp(n+1) {
    str = new char[n+1];
    strcpy(str, t.c_str());

    // build SA
    vector<int> g(n+1, 0), b(n+1, 0);
    for (int i = 0; i <= n; ++i) { sa[i] = i; g[i] = str[i]; }
    sort(begin(sa), end(sa), SAComp(0, g));
    for (int h = 1; b[n] != n; h *= 2) {
      SAComp comp(h, g);
      sort(sa.begin(), sa.end(), comp);
      for (int i = 0; i < n; ++i)
        b[i+1] = b[i] + comp(sa[i], sa[i+1]);
      for (int i = 0; i <= n; ++i)
        g[sa[i]] = b[i];
    }

    // build LCP
    int h = 0;
    for (int i = 0; i <= n; ++i) b[sa[i]] = i;
    for (int i = 0; i <= n; ++i) {
      if (b[i]) {
        for (int j = sa[b[i]-1]; j+h<n && i+h<n && str[j+h] == str[i+h]; ++h);
        lcp[b[i]] = h;
      }
      else {
        lcp[b[i]] = -1;
      }
      if (h > 0) --h;
    }
  }
  ~SuffixArray() { delete []str; }

  int find(string t) {
    int m = t.size();
    char p[m+1];
    strcpy(p, t.c_str());
    int left = -1, right = n + 1;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      if (strncmp(str + sa[mid], p, m) < 0) left = mid;
      else right = mid;
    }
    return strncmp(str + sa[right], p, m) == 0 ? sa[right] : -1;
  }
};

class LCP {
  int n;
  vector<int> mapsto;
  SegmentTree<int,min> seg;
public:
  LCP(const string &str) : n(str.size()), mapsto(n), seg(n, inf<int>) {
    SuffixArray sa(str);
    for (int i = 0; i < n; ++i) mapsto[sa.sa[i+1]] = i;
    for (int i = 0; i < n-1; ++i) seg.update(i, sa.lcp[i+2]);
  }
  int query(int i, int j) {
    if (i == j) return n - i;
    i = mapsto[i]; j = mapsto[j];
    return seg.find(min(i, j), max(i, j));
  }
};
```

- [Back](../)
