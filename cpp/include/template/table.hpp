#include "includes.hpp"

template <typename T> std::vector<T> table(int n, T v) {
  return vector<T>(n, v);
}

template <class... Args> auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}
