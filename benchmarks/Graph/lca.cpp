#include "../util.hpp"

double test_lca() {
  auto g = random_tree(array_len);
  LCA lca(g, 0);
  vector<Query> query = random_query();
  Timer timer;
  int sum = 0;
  for (auto q: query) sum += lca.query(q.left, q.right - 1);
  for (auto q: query) sum -= lca.query(q.left, q.right - 1);
  assert (sum == 0);
  return timer.stop() / (query_num * 2);
}
