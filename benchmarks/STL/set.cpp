#include "../util.hpp"

double test_set() {
  set<int> s;
  vector<int> query = random_array();
  Timer timer;
  for (auto i: query) s.insert(i);
  for (auto i: query) {
    auto it = s.lower_bound(i);
    if (it != s.end()) s.erase(it);
  }
  return timer.stop() / (array_len * 2);
}
