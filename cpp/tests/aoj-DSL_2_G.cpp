#include "../include/structure/rars.cpp"
#include "../include/template/typedef.hpp"

int main() {
  int n, q, com, s, t, x;
  scanf("%d%d", &n, &q);
  RARS<ll> bit(n + 1);
  while (q--) {
    scanf("%d%d%d", &com, &s, &t);
    if (com)
      printf("%lld\n", bit.query(s, t + 1));
    else {
      scanf("%d", &x);
      bit.update(s, t + 1, x);
    }
  }
  return 0;
}
