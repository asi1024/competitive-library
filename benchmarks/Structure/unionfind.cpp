#include "../gen_query.hpp"

vector<int> test_unionfind(vector<Query> query) {
  UnionFind uf(array_len);
  vector<int> res;
  for (auto q: query) {
    if (q.type) uf.unite(q.left, q.right);
    else res.push_back(uf.same(q.pos, q.left));
  }
  return res;
}
