#include "../src/Structure/unionfind.cpp"

int main() {
  int n, q, com, x, y;
  cin >> n >> q;
  UnionFind uf(n);
  while (q--) {
    cin >> com >> x >> y;
    if (com) cout << uf.same(x, y) << endl;
    else uf.unite(x, y);
  }
  return 0;
}
