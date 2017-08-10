#include <bits/stdc++.h>

// #define BEGIN_STACK_EXTEND(size) void * stack_extend_memory_ = malloc(size);void * stack_extend_origin_memory_;char * stack_extend_dummy_memory_ = (char*)alloca((1+(int)(((long long)stack_extend_memory_)&127))*16);*stack_extend_dummy_memory_ = 0;asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp":"=b"(stack_extend_origin_memory_):"a"((char*)stack_extend_memory_+(size)-1024));
// #define END_STACK_EXTEND asm volatile("mov %%rax, %%rsp"::"a"(stack_extend_origin_memory_));free(stack_extend_memory_);

using namespace std;

using ll = long long;

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

template<typename T>
struct skew_heap {
  T val;
  skew_heap *l, *r;
  skew_heap(T v) : val(v), l(nullptr), r(nullptr) {}
};

template<typename T>
skew_heap<T> *meld(skew_heap<T> *a, skew_heap<T> *b) {
  if (!a) return b;
  if (!b) return a;
  if (a->val > b->val) swap(a, b);
  a->r = meld(a->r, b);
  swap(a->l, a->r);
  return a;
}

template<typename T>
skew_heap<T> *push(skew_heap<T> *h, T v) {
  skew_heap<T> *p = new skew_heap<T>(v);
  return meld(h, p);
}

template<typename T>
skew_heap<T> *pop(skew_heap<T> *h) {
  skew_heap<T> *res = meld(h->l, h->r);
  free(h);
  return res;
}

using Heap = skew_heap<tuple<int,int,int>>*;

vector<pair<int,int>> g[128000];
vector<tuple<int,int,int>> t[128000];

int res[256000];
bool visited[128000];

void merge(set<int> &s1, set<int> &s2) {
  if (s1.size() < s2.size()) s1.swap(s2);
  for (int i: s2) s1.insert(i);
}

pair<set<int>,Heap> dfs(int v) {
  visited[v] = true;
  set<int> se;
  Heap heap = nullptr;
  for (auto e: t[v]) {
    int w, c, id; tie(w, c, id) = e;
    if (visited[w]) continue;
    set<int> s; Heap h = nullptr;
    tie(s, h) = dfs(w);
    int cost = 11e8, from, to;
    bool ok = false;
    while (h) {
      tie(cost, from, to) = h->val;
      if (s.find(from) == end(s) || s.find(to) == end(s)) { ok = true; break; }
      h = pop(h);
    }
    res[id] = (ok ? cost - c : -1);
    heap = meld(heap, h);
    merge(se, s);
  }
  se.insert(v);
  for (auto e: g[v]) {
    int w, c; tie(w, c) = e;
    heap = push(heap, make_tuple(c, v, w));
  }
  return make_pair(move(se), heap);
}

int main() {
  // BEGIN_STACK_EXTEND(128*1024*1024);
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  ll sum = 0;
  vector<tuple<int,int,int,int>> edges;
  for (int i = 0; i < m; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    edges.emplace_back(c, u - 1, v - 1, i);
  }
  sort(begin(edges), end(edges));
  int cnt = 0;
  for (auto e: edges) {
    int c, u, v, i; tie(c, u, v, i) = e;
    if (uf.unite(u, v)) {
      sum += c;
      t[u].emplace_back(v, c, i);
      t[v].emplace_back(u, c, i);
      ++cnt;
    }
    else {
      g[u].emplace_back(v, c);
      g[v].emplace_back(u, c);
    }
  }
  dfs(0);
  for (int i = 0; i < m; ++i) {
    cout << (res[i] == -1 || cnt < n - 1 ? -1 : res[i] + sum) << endl;
  }
  // END_STACK_EXTEND;
  return 0;
}
