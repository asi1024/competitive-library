#include <unordered_map>

#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"

int main() {
  std::unordered_map<long long, long long> m;
  int Q;
  fcin >> Q;
  while (Q--) {
    long long op, k, v;
    fcin >> op >> k;
    k ^= 1234567;  // Dodges unordered_map_killer
    if (op == 0) {
      fcin >> v;
      m[k] = v;
    }
    else {
      long long res = m.count(k) ? m[k] : 0LL;
      fcout << res << fendl;
    }
  }
  return 0;
}
