#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"
#include "../include/structure/monoid.cpp"
#include "../include/structure/segment_tree.cpp"

struct Monoid {
  using value_type = std::vector<int>;
  static value_type id() { return value_type(); }
  static value_type op(const value_type &l, const value_type &r) {
    std::vector<int> res(l.size() + r.size());
    std::merge(l.begin(), l.end(), r.begin(), r.end(), res.begin());
    return res;
  }
};

int main() {
  int n, q;
  fcin >> n >> q;
  std::vector<std::vector<int>> vec(n);
  for (int i = 0; i < n; ++i) {
    int x;
    fcin >> x;
    vec[i] = std::vector<int>(1, x);
  }
  SegmentTree<Monoid> seg(vec);
  while (q--) {
    int l, r, k;
    fcin >> l >> r >> k;
    auto itrs = seg.range_iterators(l, r);
    int lb = -1, ub = 1000000001;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      int cnt_less = 0;
      for (auto &&it : itrs) {
        cnt_less += std::lower_bound(it->begin(), it->end(), mid) - it->begin();
      }
      *(cnt_less > k ? &ub : &lb) = mid;
    }
    fcout << lb << fendl;
  }
  return 0;
}
