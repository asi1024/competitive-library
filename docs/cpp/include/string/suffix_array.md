### Includes

- [segment_tree.cpp](../structure/segment_tree)

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/string/suffix_array.cpp)

{% highlight cpp %}
#include "../structure/segment_tree.cpp"

template<typename string_t>
struct SuffixArray {
  struct SAComp {
    const int h;
    const vector<int> &g;
    SAComp(int h_, vector<int> &g_) : h(h_), g(g_) {;}
    bool operator() (int a, int b) {
      return a != b && (g[a] != g[b] ? g[a] < g[b] : g[a + h] < g[b + h]);
    }
  };

  int n;
  string_t str;
  vector<int> sa, lcp;

  SuffixArray(const string_t &t) : n(t.size()), str(t), sa(n + 1), lcp(n + 1) {
    // build SA
    vector<int> g(n + 1, 0), b(n + 1, 0);
    for (int i = 0; i <= n; ++i) { sa[i] = i; g[i] = str[i]; }
    sort(begin(sa), end(sa), SAComp(0, g));
    for (int h = 1; b[n] != n; h *= 2) {
      SAComp comp(h, g);
      sort(sa.begin(), sa.end(), comp);
      for (int i = 0; i < n; ++i) b[i+1] = b[i] + comp(sa[i], sa[i+1]);
      for (int i = 0; i <= n; ++i) g[sa[i]] = b[i];
    }
    // build LCP
    int h = 0;
    for (int i = 0; i <= n; ++i) b[sa[i]] = i;
    for (int i = 0; i <= n; ++i) {
      if (b[i]) {
        int j = sa[b[i] - 1];
        while (j + h < n && i + h < n && str[j+h] == str[i+h]) ++h;
        lcp[b[i]] = h;
      }
      else {
        lcp[b[i]] = -1;
      }
      if (h > 0) --h;
    }
  }

  template<class Compare>
  int binary_search(const string_t &t) const {
    int m = t.size();
    int lb = -1, ub = n + 1;
    while (lb + 1 < ub) {
      int mid = (lb + ub) / 2;
      if (Compare()(strncmp(str.c_str() + sa[mid], t.c_str(), m), 0)) lb = mid;
      else ub = mid;
    }
    return ub;
  }
  int lower_bound(const string_t &t) const {
    return binary_search<less<int>>(t);
  }
  int upper_bound(const string_t &t) const {
    return binary_search<less_equal<int>>(t);
  }
  int find(const string_t &t) const {
    const int m = t.size();
    int res = lower_bound(t);
    return strncmp(str.c_str() + sa[res], t.c_str(), m) == 0 ? sa[res] : -1;
  }
};

class LCP {
  int n;
  vector<int> mapsto;
  SegmentTree<RMQ> seg;
public:
  LCP(const string &str) : n(str.size()), mapsto(n), seg(n) {
    SuffixArray<string> sa(str);
    for (int i = 0; i < n; ++i) mapsto[sa.sa[i+1]] = i;
    for (int i = 0; i < n-1; ++i) seg.update(i, sa.lcp[i+2]);
  }
  int query(int i, int j) {
    if (i == j) return n - i;
    i = mapsto[i]; j = mapsto[j];
    return seg.query(min(i, j), max(i, j));
  }
};
{% endhighlight %}

[Back](../..)
