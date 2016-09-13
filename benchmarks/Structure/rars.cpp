#include "../gen_query.hpp"

vector<ll> test_rars(vector<Query> query) {
  RARS<ll> seg(array_len);
  vector<ll> res;
  for (auto q: query) {
    if (q.type) seg.add(q.left, q.right, q.value);
    else res.push_back(seg.sum(q.left, q.right));
  }
  return res;
}
