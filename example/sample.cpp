#include "include/structure/fenwick_tree.cpp"
#include "include/template/template.cpp"

int main() {
  int n, q, com, x, y;
  cin >> n >> q;
  FenwickTree<int> bit(n + 1);
  while (q--) {
    cin >> com >> x >> y;
    if (com) cout << bit.sum(x, y + 1) << endl;
    else bit.add(x, y);
  }
  return 0;
}
