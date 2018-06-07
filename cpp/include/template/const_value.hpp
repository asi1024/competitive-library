#include "includes.hpp"

#pragma once

template <typename T>
constexpr typename std::enable_if<std::is_integral<T>::value, T>::type
inf() {
  return std::numeric_limits::max() / 2 - 1000;
}

template <typename T>
constexpr typename std::enable_if<std::is_floating_point<T>::value, T>::type
inf() {
  return 1e30;
}

template <typename T>
constexpr typename std::enable_if<std::is_arithmetic<T>::value, T>::type
zero() {
  return T(0);
}

const long double pi = acos(-1.0);
