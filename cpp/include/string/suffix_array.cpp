#pragma once

#include "../util.hpp"
#include "../structure/segment_tree.cpp"

template<typename string_t>
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

  int find(const string_t &t) {
    int m = t.size();
    int left = -1, right = n + 1;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      if (strncmp(str.c_str() + sa[mid], t.c_str(), m) < 0) left = mid;
      else right = mid;
    }
    return strncmp(str.c_str() + sa[right], t.c_str(), m) == 0 ? sa[right] : -1;
  }

  int lower_bound(const string_t &t) {
    int m = t.size();
    int left = -1, right = n + 1;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      if (strncmp(str.c_str() + sa[mid], t.c_str(), m) < 0) left = mid;
      else { right = mid; }
    }
    return right;
  }

  int upper_bound(const string_t &t) {
    int m = t.size();
    int left = -1, right = n + 1;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      if (strncmp(str.c_str() + sa[mid], t.c_str(), m) <= 0) left = mid;
      else { right = mid; }
    }
    return right;
  }
};

// class LCP {
//   int n;
//   vector<int> mapsto;
//   SegmentTree<RMQ> seg;
// public:
//   LCP(const string &str) : n(str.size()), mapsto(n), seg(n) {
//     SuffixArray sa(str);
//     for (int i = 0; i < n; ++i) mapsto[sa.sa[i+1]] = i;
//     for (int i = 0; i < n-1; ++i) seg.update(i, sa.lcp[i+2]);
//   }
//   int query(int i, int j) {
//     if (i == j) return n - i;
//     i = mapsto[i]; j = mapsto[j];
//     return seg.find(min(i, j), max(i, j));
//   }
// };
