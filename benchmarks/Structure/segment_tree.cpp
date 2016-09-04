#include "../util.hpp"
#include "../../src/Structure/segment_tree.cpp"

double test_segment_tree() {
  SegmentTree<int, min> seg(array_len, 0x7FFFFFFF);
  vector<Query> query = random_query();
  Timer timer;
  for (auto q: query) {
    if (q.type) seg.update(q.pos, q.value);
    else seg.find(q.left, q.right);
  }
  return timer.stop() / query_num;
}
