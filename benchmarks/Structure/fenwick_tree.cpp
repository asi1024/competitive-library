#include "../util.hpp"
#include "../../src/Structure/fenwick_tree.cpp"

double test_fenwick_tree() {
  FenwickTree<int> seg(array_len);
  vector<Query> query = random_query();
  Timer timer;
  for (auto q: query) {
    if (q.type) seg.add(q.pos, q.value);
    else seg.sum(q.pos);
  }
  return timer.stop() / query_num;
}
