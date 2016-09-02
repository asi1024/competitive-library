#pragma once

#include <random>

const int array_len = 200000;
const int query_num = 1000000;

std::mt19937 mt(0);

class Query {
public:
  int type, pos, left, right, value;
  Query(int len) :
    type(mt() % 2),
    pos(mt() % len), left(mt() % len), right(mt() % len),
    value(mt() % 1000)
  {
    if (left > right) std::swap(left, right);
    ++right;
  }
};

class Timer {
  double start;
public:
  Timer() : start(clock()) {}
  double stop() { return (clock() - start) / CLOCKS_PER_SEC; }
};
