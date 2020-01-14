#include "includes.cpp"

template <typename T> std::vector<T> table(int n, T v) {
  return std::vector<T>(n, v);
}

template <class... Args> auto table(int n, Args... args) {
  auto val = table(args...);
  return std::vector<decltype(val)>(n, std::move(val));
}
