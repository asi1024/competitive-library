#include "../util.hpp"

vector<int> test_segment_tree(vector<Query> query) {
  SegmentTree<int,min> seg(array_len, 0x7FFFFFFF);
  vector<int> res;
  for (auto q: query) {
    if (q.type) seg.update(q.pos, q.value);
    else res.push_back(seg.find(q.left, q.right));
  }
  return res;
}
