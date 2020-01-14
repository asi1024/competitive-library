#pragma once

#include "../template/includes.cpp"

template <typename T> struct LeftHandSide {
  using value_type = T;
  static value_type op(const value_type &l, const value_type &) { return l; }
};
