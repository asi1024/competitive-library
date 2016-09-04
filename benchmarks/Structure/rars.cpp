#include "../util.hpp"
#include "../../src/Structure/rars.cpp"

double test_rars() {
  RARS<int> seg(array_len);
  vector<Query> query = random_query();
  Timer timer;
  for (auto q: query) {
    if (q.type) seg.add(q.left, q.right, q.value);
    else seg.sum(q.left, q.right);
  }
  return timer.stop() / query_num;
}
