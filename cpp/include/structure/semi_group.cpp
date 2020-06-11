#pragma once

#include "../template/includes.cpp"

template <typename T> struct RightHandSide {
  using value_type = T;
  static value_type op(const value_type &, const value_type &r) { return r; }
};
