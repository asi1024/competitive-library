#include "../util.hpp"

double test_slide_min() {
  vector<Query> query = random_query();
  SlideMin<int> smin(10000);
  Timer timer;
  for (auto q: query) smin.query(q.value);
  return timer.stop() / query_num;
}
