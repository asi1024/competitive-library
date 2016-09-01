#pragma once

#include "../util.hpp"

template<typename T>
vector<T> operator-(vector<T> v) {
  transform(begin(v), end(v), begin(v), [](T n){ return -n; });
  return v;
}

template<typename T>
void operator+=(vector<T> &l, const vector<T> &r) {
  transform(begin(l), end(l), begin(r), begin(l), plus<T>());
}

template<typename T>
void operator-=(vector<T> &l, const vector<T> &r) {
  transform(begin(l), end(l), begin(r), begin(l), minus<T>());
}

namespace std {
  template<typename T>
  vector<T> operator+(vector<T> l, const vector<T> &r) { l += r; return l; }
  template<typename T>
  vector<T> operator-(vector<T> l, const vector<T> &r) { l -= r; return l; }
}

template<typename T>
T dot(const vector<T> &a, const vector<T> &b) {
  return inner_product(begin(a), end(a), begin(b), T(0));
}

template<typename T>
T norm(const vector<T> &a) { return dot(a, a); }
