#include "../util.hpp"

struct Data {
  int n;
  Data() : n(INT_MAX) {}
  Data(int n) : n(n) {}
};

Data merge(const Data &a, const Data &b) {
  return Data(min(a.n, b.n));
}

double test_segment_tree() {
  SegmentTree<Data> seg(vector<Data>(array_len, Data()));
  vector<Query> query = random_query();
  Timer timer;
  for (auto q: query) {
    if (q.type) seg.update(q.pos, q.value);
    else seg.find(q.left, q.right);
  }
  return timer.stop() / query_num;
}
