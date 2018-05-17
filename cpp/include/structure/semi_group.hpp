#pragma once

#include "../template/includes.hpp"

template <typename T> struct RightHandSide {
  using value_type = T;
  static value_type op(const value_type &l, const value_type &r) { return r; }
};
