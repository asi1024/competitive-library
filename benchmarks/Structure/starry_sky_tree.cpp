#include "../util.hpp"

vector<int> test_starry_sky_tree(vector<Query> query) {
  StarrySkyTree<int> seg(array_len);
  vector<int> res;
  for (auto q: query) {
    if (q.type) seg.add(q.left, q.right, q.value);
    else res.push_back(seg.minimum(q.left, q.right));
  }
  return res;
}
