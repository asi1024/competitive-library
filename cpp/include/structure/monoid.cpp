#pragma once

#include "../template/const_value.cpp"
#include "../template/includes.cpp"

template <typename T> struct RMQ {
  using value_type = T;
  static value_type id() { return inf<value_type>(); }
  static value_type op(const value_type &l, const value_type &r) {
    return std::min(l, r);
  }
};

template <typename T> struct Linear {
  using value_type = std::pair<T, T>;
  static value_type id() { return value_type(1, 0); }
  static value_type op(const value_type &l, const value_type &r) {
    return value_type(l.first * r.first, l.second * r.first + r.second);
  }
};

template <typename T> struct RightHandSide {
  using value_type = std::pair<bool, T>;
  static value_type id() { return value_type(false, T()); }
  static value_type op(const value_type &l, const value_type &r) {
    return r.first ? r : l;
  }
};
