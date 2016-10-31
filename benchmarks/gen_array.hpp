#pragma once

#include "testsuite.hpp"

TestSuite<vector<int>> random_array() {
  mt19937 mt(1);
  TestSuite<vector<int>> res;
  for (int c = 0; c < 20; ++c) {
    vector<int> ary(array_len);
    for (auto &i: ary) i = mt();
    res.add(ary, "Array : len = 200000");
  }
  return res;
}
