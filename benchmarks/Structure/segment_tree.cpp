#include "../util.hpp"
#include "../../src/Structure/segment_tree.cpp"

void test_segment_tree() {
  SegmentTree<int> seg(array_len, 0x7FFFFFFF, [](int a, int b){return min(a, b);});
  vector<Query> query(query_num, array_len);
  Timer timer;
  for (auto q: query) {
    if (q.type) seg.update(q.pos, q.value);
    else seg.find(q.left, q.right);
  }
  cout << "SegmentTree (Array Size = " << array_len <<
    ", Query Num  = " << query_num << ")" << endl;
  cout << "  Time : " << timer.stop() << endl;
}
