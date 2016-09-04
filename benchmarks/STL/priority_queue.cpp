#include "../util.hpp"

double test_priority_queue() {
  vector<int> ary = random_array();
  priority_queue<int> que;
  Timer timer;
  for (auto i: ary) que.push(i);
  while (!que.empty()) que.pop();
  return timer.stop() / (array_len * 2);
}
