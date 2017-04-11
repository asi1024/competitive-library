#include "../include/structure/segment_tree.cpp"

struct RMQ {
  using type = int;
  static type id() { return inf<int>; }
  static type op(const type &l, const type &r) { return min(l, r); }
};

int main() {
  int n, q, com, x, y;
  scanf("%d%d", &n, &q);
  SegmentTree<RMQ> seg(n);
  while (q--) {
    scanf("%d%d%d", &com, &x, &y);
    if (com) printf("%d\n", seg.query(x, y + 1));
    else seg.update(x, y);
  }
  return 0;
}
