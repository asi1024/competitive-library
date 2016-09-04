#include "../util.hpp"
#include "../../src/Structure/unionfind.cpp"

double test_unionfind() {
  UnionFind uf(array_len);
  vector<Query> query = random_query();
  Timer timer;
  for (auto q: query) {
    if (q.type) uf.unite(q.left, q.right);
    else uf.same(q.left, q.right);
  }
  return timer.stop() / query_num;
}
