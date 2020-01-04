#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"
#include "../include/structure/fenwick_tree.cpp"

int main() {
  int n, q, com, l, r;
  fcin >> n >> q;
  FenwickTree<long long> bit(n + 1);
  for (int i = 0; i < n; ++i) {
    fcin >> l;
    bit.add(i, l);
  }
  while (q--) {
    fcin >> com >> l >> r;
    if (com == 0) {
      bit.add(l, r);
    }
    else {
      fcout << bit.sum(l, r) << fendl;
    }
  }
  return 0;
}
