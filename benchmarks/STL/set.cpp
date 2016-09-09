#include "../util.hpp"

vector<int> test_set(const vector<int> &ary) {
  vector<int> res;
  set<int> s;
  for (auto i: ary) s.insert(i);
  for (auto i: ary) {
    auto it = s.lower_bound(i);
    res.push_back(*it);
    if (it != s.end()) s.erase(it);
  }
  return res;
}
