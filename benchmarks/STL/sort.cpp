#include "../util.hpp"

double test_sort() {
  vector<int> ary = random_array();
  Timer timer;
  sort(begin(ary), end(ary));
  return timer.stop() / array_len;
}
