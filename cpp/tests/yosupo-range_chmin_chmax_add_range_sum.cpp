#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"
#include "../include/structure/segment_tree_beats.cpp"
#include "../include/template/typedef.cpp"

int main() {
  int n, q;
  fcin >> n >> q;
  std::vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    fcin >> a[i];
  }
  SegmentTreeBeats<ll> seg(a);
  while (q--) {
    int t, l, r;
    ll x = 0;
    fcin >> t >> l >> r;
    if (t == 0) {
      fcin >> x;
      seg.chmin(l, r, x);
    }
    else if (t == 1) {
      fcin >> x;
      seg.chmax(l, r, x);
    }
    else if (t == 2) {
      fcin >> x;
      seg.add(l, r, x);
    }
    else {
      fcout << seg.sum(l, r) << fendl;
    }
  }
  return 0;
}
