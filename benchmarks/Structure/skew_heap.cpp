#include "../util.hpp"

double test_skew_heap() {
  vector<int> ary = random_array();
  Heap<int> *que = nullptr;
  Timer timer;
  for (auto i: ary) que = push(que, i);
  while (!que) que = pop(que);
  return timer.stop() / (array_len * 2);
}
