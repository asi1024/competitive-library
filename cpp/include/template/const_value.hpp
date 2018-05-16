#pragma once

template<> constexpr int inf<int>() { return 1e9; }
template<> constexpr long long inf<long long>() { return 1e18; }
template<> constexpr long double inf<long double>() { return 1e30; }
template<typename T> T inf();

template<> constexpr int zero<int>() { return 0; }
template<> constexpr long long zero<long long>() { return 0; }
template<> constexpr long double zero<long double>() { return 0; }
template<typename T> T zero();
