#include "../util.hpp"
#include "../../src/Structure/starry_sky_tree.cpp"

void test_starry_sky_tree() {
  StarrySkyTree<int> seg(array_len);
  std::vector<Query> query(query_num, array_len);
  Timer timer;
  for (auto q: query) {
    if (q.type) seg.add(q.left, q.right, q.value);
    else seg.query(q.left, q.right);
  }
  cout << "StarrySkyTree (Array Size = " << array_len <<
    ", Query Num  = " << query_num << ")" << endl;
  cout << "  Time : " << timer.stop() << endl;
}
