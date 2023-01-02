---
title: "segment_tree_beats.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/segment_tree_beats.cpp)

{% highlight cpp %}
#include "../template/bit_operation.cpp"
#include "../template/const_value.cpp"

template <typename T> class SegmentTreeBeats {
private:
  static constexpr T INF = inf<T>();
  int size_, log_, n;

  struct Node {
    T sum, add, ma1, mi1, ma2, mi2;
    int maxc, minc;
    Node(T x) :
      sum(x), add(0), ma1(x), mi1(x), ma2(-INF), mi2(INF), maxc(1), minc(1) {}
    Node() : Node(0) {}
  };

  std::vector<Node> nodes;

private:
  void update(int i) {
    Node &p = nodes[i];
    const Node &l = nodes[i * 2 + 0], &r = nodes[i * 2 + 1];
    p.sum = l.sum + r.sum;

    if (l.ma1 == r.ma1) {
      p.ma1 = l.ma1, p.ma2 = std::max(l.ma2, r.ma2);
      p.maxc = l.maxc + r.maxc;
    }
    else if (l.ma1 > r.ma1) {
      p.ma1 = l.ma1, p.ma2 = std::max(r.ma1, l.ma2);
      p.maxc = l.maxc;
    }
    else {
      p.ma1 = r.ma1, p.ma2 = std::max(l.ma1, r.ma2);
      p.maxc = r.maxc;
    }

    if (l.mi1 == r.mi1) {
      p.mi1 = l.mi1, p.mi2 = std::min(l.mi2, r.mi2);
      p.minc = l.minc + r.minc;
    }
    else if (l.mi1 < r.mi1) {
      p.mi1 = l.mi1, p.mi2 = std::min(r.mi1, l.mi2);
      p.minc = l.minc;
    }
    else {
      p.mi1 = r.mi1, p.mi2 = std::min(l.mi1, r.mi2);
      p.minc = r.minc;
    }
  }

  void add_step(Node &p, T value, int cnt) {
    p.sum += value * cnt, p.ma1 += value, p.mi1 += value;
    p.add += value;
    if (p.ma2 != -INF) p.ma2 += value;
    if (p.mi2 != INF) p.mi2 += value;
  }

  void min_step(Node &p, T value) {
    p.sum += (value - p.ma1) * p.maxc;
    if (p.mi1 == p.ma1) p.mi1 = value;
    if (p.mi2 == p.ma1) p.mi2 = value;
    p.ma1 = value;
  }

  void max_step(Node &p, T value) {
    p.sum += (value - p.mi1) * p.minc;
    if (p.ma1 == p.mi1) p.ma1 = value;
    if (p.ma2 == p.mi1) p.ma2 = value;
    p.mi1 = value;
  }

  void pushdown(int i) {
    Node &p = nodes[i], &l = nodes[i * 2 + 0], &r = nodes[i * 2 + 1];
    if (p.add != 0) {
      int cnt = 1 << (log_ - lg(i + 1));
      add_step(l, p.add, cnt);
      add_step(r, p.add, cnt);
      p.add = 0;
    }
    if (p.ma1 < l.ma1) min_step(l, p.ma1);
    if (p.mi1 > l.mi1) max_step(l, p.mi1);
    if (p.ma1 < r.ma1) min_step(r, p.ma1);
    if (p.mi1 > r.mi1) max_step(r, p.mi1);
  }

  void chmin_sub(int i, T value) {
    if (value >= nodes[i].ma1) return;
    if (value > nodes[i].ma2) {
      min_step(nodes[i], value);
    }
    else {
      pushdown(i);
      chmin_sub(i * 2 + 0, value);
      chmin_sub(i * 2 + 1, value);
      update(i);
    }
  }

  void chmax_sub(int i, T value) {
    if (value <= nodes[i].mi1) return;
    if (value < nodes[i].mi2) {
      max_step(nodes[i], value);
    }
    else {
      pushdown(i);
      chmax_sub(i * 2 + 0, value);
      chmax_sub(i * 2 + 1, value);
      update(i);
    }
  }

  void add_sub(int i, T value) {
    int cnt = 1 << (log_ - lg(i + 1) + 1);
    add_step(nodes[i], value, cnt);
  }

  template <class Func> void apply(int l, int r, Func apply_sub) {
    assert(0 <= l);
    assert(l <= r);
    assert(r <= size_);
    if (l == r) return;
    l += n, r += n;
    for (int i = log_; i >= 1; i--) {
      int mask = (1 << i) - 1;
      if (l & mask) pushdown(l >> i);
      if (r & mask) pushdown((r - 1) >> i);
    }
    int l_ = l, r_ = r;
    while (l_ < r_) {
      if (l_ & 1) apply_sub(l_++);
      if (r_ & 1) apply_sub(--r_);
      l_ >>= 1;
      r_ >>= 1;
    }
    for (int i = 1; i <= log_; i++) {
      int mask = (1 << i) - 1;
      if (l & mask) update(l >> i);
      if (r & mask) update((r - 1) >> i);
    }
  }

  template <class Func, class Merge>
  T query(int l, int r, T id, Func f, Merge merge) {
    assert(0 <= l);
    assert(l <= r);
    assert(r <= size_);
    if (l == r) return id;
    l += n, r += n;
    for (int i = log_; i >= 1; i--) {
      int mask = (1 << i) - 1;
      if (l & mask) pushdown(l >> i);
      if (r & mask) pushdown((r - 1) >> i);
    }
    T lval = id, rval = id;
    while (l < r) {
      if (l & 1) lval = f(lval, nodes[l++]);
      if (r & 1) rval = f(rval, nodes[--r]);
      l >>= 1;
      r >>= 1;
    }
    return merge(lval, rval);
  }

public:
  SegmentTreeBeats(int size) : SegmentTreeBeats(std::vector<T>(size)) {}
  SegmentTreeBeats(const std::vector<T> &vec) :
    size_(vec.size()), log_(lg(size_)), n(1 << log_), nodes(2 * n) {
    std::copy(vec.begin(), vec.end(), nodes.begin() + n);
    for (int i = n - 1; i; --i) update(i);
  }

  void chmin(int l, int r, T value) {
    apply(l, r, [&](int i) { chmin_sub(i, value); });
  }
  void chmax(int l, int r, T value) {
    apply(l, r, [&](int i) { chmax_sub(i, value); });
  }
  void add(int l, int r, T value) {
    apply(l, r, [&](int i) { add_sub(i, value); });
  }

  T min(int l, int r) {
    auto f = [](T x, const Node &y) -> T { return std::min(x, y.mi1); };
    auto merge = [](T x, T y) -> T { return std::min(x, y); };
    return query(l, r, INF, f, merge);
  }
  T max(int l, int r) {
    auto f = [](T x, const Node &y) -> T { return std::max(x, y.ma1); };
    auto merge = [](T x, T y) -> T { return std::max(x, y); };
    return query(l, r, -INF, f, merge);
  }
  T sum(int l, int r) {
    auto f = [](T x, const Node &y) -> T { return x + y.sum; };
    auto merge = [](T x, T y) -> T { return x + y; };
    return query(l, r, 0, f, merge);
  }
};
{% endhighlight %}

### Includes

- [bit_operation.cpp](../template/bit_operation)
- [const_value.cpp](../template/const_value)

[Back](../..)
