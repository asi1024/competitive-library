#include "../util.hpp"

vector<int> test_priority_queue(vector<int> ary) {
  vector<int> res;
  priority_queue<int> que;
  for (auto i: ary) que.push(i);
  while (!que.empty()) {
    res.push_back(que.top());
    que.pop();
  }
  return res;
}
