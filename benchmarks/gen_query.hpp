#pragma once

#include "testsuite.hpp"

class Query {
public:
  int type, pos, left, right, value, value_small;
  Query(int len, int type, mt19937 &mt) :
    type(type),
    pos(mt() % len), left(mt() % len), right(mt() % len),
    value(int(mt()) % 1000000)
  {
    value_small = value % 1000;
    if (left > right) swap(left, right);
    ++right;
  }
};

TestSuite<vector<Query>> random_query() {

  mt19937 mt(2);
  TestSuite<vector<Query>> res;
  for (int i = 0; i < 10; ++i) {
    vector<Query> query;
    for (int j = 0; j < query_num / 2; ++j) {
      query.push_back(Query(array_len, 0, mt));
      query.push_back(Query(array_len, 1, mt));
    }
    shuffle(begin(query), end(query), mt);
    res.add(query, "500000 update and 500000 find");
  }
  for (int i = 0; i < 5; ++i) {
    vector<Query> query;
    for (int j = 0; j < query_num; ++j) {
      query.push_back(Query(array_len, 0, mt));
    }
    res.add(query, "1000000 find queries");
  }
  for (int i = 0; i < 5; ++i) {
    vector<Query> query;
    for (int j = 0; j < query_num; ++j) {
      query.push_back(Query(array_len, 1, mt));
    }
    res.add(query, "1000000 update queries");
  }
  return res;
}
