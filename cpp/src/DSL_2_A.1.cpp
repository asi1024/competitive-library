#include "../include/structure/starry_sky_tree.cpp"

int main() {
  int n, q, com, x, y;
  scanf("%d%d", &n, &q);
  StarrySkyTree<ll> seg(n);
  seg.add(0, n, INT_MAX);
  while (q--) {
    scanf("%d%d%d", &com, &x, &y);
    if (com) printf("%lld\n", seg.minimum(x, y + 1));
    else {
      int val = seg.minimum(x, x + 1);
      seg.add(x, x + 1, y - val);
    }
  }
  return 0;
}
