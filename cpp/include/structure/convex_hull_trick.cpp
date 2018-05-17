#pragma once

#include "../util.hpp"

template <class Data> struct ConvexHullTrick {
  deque<pair<Data, Data>> l;
  bool check(pair<Data, Data> l3) {
    const auto l1 = *prev(end(l), 2);
    const auto l2 = *prev(end(l), 1);
    Data a = (l2.first - l1.first) * (l3.second - l2.second);
    Data b = (l2.second - l1.second) * (l3.first - l2.first);
    return a >= b;
  }
  bool empty() const { return l.empty(); }
  void add(Data a, Data b) {
    if (!empty())
      assert(l.back().first >= a);
    pair<Data, Data> n(a, b);
    while ((int)l.size() >= 2 && check(n))
      l.pop_back();
    l.emplace_back(n);
  }
  Data f(int k, Data x) { return l[k].first * x + l[k].second; }
  Data minimum(Data x) {
    assert(!empty());
    while ((int)l.size() >= 2 && f(0, x) >= f(1, x))
      l.pop_front();
    return f(0, x);
  }
};
