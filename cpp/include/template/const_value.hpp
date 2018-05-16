#include "includes.hpp"

#pragma once

template<typename T> constexpr T inf();
template<> constexpr int inf<int>() { return 1e9; }
template<> constexpr long long inf<long long>() { return 1e18; }
template<> constexpr long double inf<long double>() { return 1e30; }


template<typename T> T constexpr zero();

template<typename T> constexpr
typename std::enable_if<std::is_integral<T>::value, T>::type
zero() { return T(0); }
