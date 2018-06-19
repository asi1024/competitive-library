#pragma once

#include "../template/bit_operation.cpp"
#include "../template/includes.hpp"

template <typename Struct> class SegmentTreeLazy {
public:
  using Monoid = typename Struct::Monoid;
  using Update = typename Struct::Update;
  using value_type = typename Struct::value_type;
  using update_type = typename Struct::update_type;

private:
  const int n;
  std::vector<value_type> data;
  std::vector<update_type> lazy;
  std::vector<bool> flag;
  void lazyset(int node, const update_type &update) {
    if (node < n) {
      if (flag[node]) {
        lazy[node] = Update::op(update, lazy[node]);
      }
      else {
        lazy[node] = update;
        flag[node] = true;
      }
    }
    data[node] = Struct::evaluate(update, data[node]);
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
  SegmentTreeLazy(int count, const value_type &init = Monoid::id()) :
    n(log2ceil(count)), data(n * 2), lazy(n), flag(n, false) {
    fill(begin(data) + n, end(data), init);
    for (int i = n - 1; i >= 1; i--) {
      data[i] = Monoid::op(data[i * 2 + 0], data[i * 2 + 1]);
    }
  };
  void update(int l, int r, const update_type &f) {
    update_sub(l, r, 1, 0, n, f);
  }
  value_type query(int l, int r) { return query_sub(l, r, 1, 0, n); }
};
