#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"
#include "../include/structure/unionfind.cpp"

int main() {
  int n, q, com, u, v;
  fcin >> n >> q;
  UnionFind uf(n);
  while (q--) {
    fcin >> com >> u >> v;
    if (com) {
      fcout << int(uf.same(u, v)) << fendl;
    }
    else {
      uf.unite(u, v);
    }
  }
  return 0;
}
