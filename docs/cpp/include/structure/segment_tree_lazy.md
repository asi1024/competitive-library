---
title: "segment_tree_lazy.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/segment_tree_lazy.cpp)

{% highlight cpp %}
#include "../template/bit_operation.cpp"
#include "../template/includes.cpp"

template <typename Struct> class SegmentTreeLazy {
public:
  using Monoid = typename Struct::Monoid;
  using Update = typename Struct::Update;
  using value_type = typename Struct::value_type;
  using update_type = typename Struct::update_type;

private:
  const int size_, n;
  std::vector<value_type> data;
  std::vector<update_type> lazy;
  std::vector<bool> flag;
  void lazyset(int node, const update_type &update) {
    if (node < n) {
      if (flag[node]) {
        lazy[node] = Update::op(lazy[node], update);
      }
      else {
        lazy[node] = update;
        flag[node] = true;
      }
    }
    data[node] = Struct::evaluate(data[node], update);
  }
  void evaluate(int node) {
    if (!flag[node]) return;
    flag[node] = false;
    lazyset(node * 2 + 0, lazy[node]);
    lazyset(node * 2 + 1, lazy[node]);
  }
  void update_sub(int l, int r, int node, int lb, int ub,
                  const update_type &update) {
    if (ub <= l || r <= lb) {
      return;
    }
    if (l <= lb && ub <= r) {
      lazyset(node, update);
      return;
    }
    evaluate(node);
    const int mid = (lb + ub) / 2;
    update_sub(l, r, node * 2 + 0, lb, mid, update);
    update_sub(l, r, node * 2 + 1, mid, ub, update);
    data[node] = Monoid::op(data[node * 2 + 0], data[node * 2 + 1]);
  }
  value_type query_sub(int l, int r, int node, int lb, int ub) {
    if (ub <= l || r <= lb) return Monoid::id();
    if (l <= lb && ub <= r) {
      return data[node];
    }
    evaluate(node);
    const int mid = (lb + ub) / 2;
    value_type lval = query_sub(l, r, node * 2 + 0, lb, mid);
    value_type rval = query_sub(l, r, node * 2 + 1, mid, ub);
    return Monoid::op(lval, rval);
  }

public:
  SegmentTreeLazy(const std::vector<value_type> &vec) :
    size_(vec.size()), n(log2ceil(size_)), data(n * 2, Monoid::id()), lazy(n),
    flag(n, false) {
    std::copy(begin(vec), end(vec), begin(data) + n);
    for (int i = n - 1; i >= 1; i--) {
      data[i] = Monoid::op(data[i * 2 + 0], data[i * 2 + 1]);
    }
  };

  SegmentTreeLazy(int count, const value_type &value = Monoid::id()) :
    SegmentTreeLazy(std::vector<value_type>(count, value)) {}

  int size() const { return size_; }

  void update(int l, int r, const update_type &f) {
    update_sub(l, r, 1, 0, n, f);
  }

  value_type query(int l, int r) { return query_sub(l, r, 1, 0, n); }
};
{% endhighlight %}

### Includes

- [bit_operation.cpp](../template/bit_operation)
- [includes.cpp](../template/includes)

[Back](../..)
