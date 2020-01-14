#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"
#include "../include/structure/monoid.cpp"
#include "../include/structure/segment_tree.cpp"

int main() {
  int n, q, l, r;
  fcin >> n >> q;
  std::vector<int> vec(n);
  for (int i = 0; i < n; ++i) fcin >> vec[i];
  SegmentTree<RMQ<int>> seg(vec);
  while (q--) {
    fcin >> l >> r;
    fcout << seg.query(l, r) << fendl;
  }
  return 0;
}
