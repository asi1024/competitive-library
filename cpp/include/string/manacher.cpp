#include "../template/includes.hpp"

template <typename string_t> std::vector<int> manacher(const string_t &s) {
  const int n = s.size();
  std::vector<int> rad(n);
  int i = 0, j = 0, k = 0;
  while (i < n) {
    while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;
    rad[i] = j;
    for (k = 1; i - k >= 0 && i + k < n && k + rad[i - k] < j; ++k) {
      rad[i + k] = rad[i - k];
    }
    i += k;
    j -= k;
  }
  return rad;
}
