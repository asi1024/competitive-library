#include "../util.hpp"

vector<int> test_fenwick_tree(vector<Query> query) {
  FenwickTree<int> bit(array_len);
  vector<int> res;
  for (auto q: query) {
    if (q.type) bit.add(q.pos, q.value_small);
    else res.push_back(bit.sum(q.pos));
  }
  return res;
}
