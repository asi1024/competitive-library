#pragma once

#include "hash.hpp"

template<typename T>
class TestSuite {
  vector<T> testset;
  vector<string> message;
  bool flag;
  template<typename Func>
  ull get_hash(Func f) {
    flag = false;
    vector<ull> hash_vec;
    const int n = testset.size();
    double worst = 0;
    for (int i = 0; i < n; ++i) {
      const auto &t = testset[i];
      double start = clock();
      auto ret = f(t);
      double s = (clock() - start) / CLOCKS_PER_SEC;
      worst = max(worst, s);
      printf("#%.2d (%s) : %.3f ms\n", i, message[i].c_str(), s * 1e3);
      hash_vec.push_back(my_hash(ret));
    }
    printf("%.3f ms\n\n", worst * 1e3);
    return my_hash(hash_vec);
  }
public:
  TestSuite() : testset(0), message(0), flag(true) {}
  void add(const T &t, const char *mes) {
    assert(flag);
    testset.push_back(t);
    message.push_back(string(mes));
  }
  template<typename Func>
  void run(const char *mes, Func f) {
    printf("=== %s ===\n", mes);
    ull ret = get_hash(f);
    cerr << "Returns:  " << ret << endl;
  }
  template<typename Func>
  void run(const char *mes, Func f, ull ans) {
    printf("=== %s ===\n", mes);
    ull ret = get_hash(f);
    if (ret != ans) {
      cerr << "Expected: " << ans << endl;
      cerr << "Returns:  " << ret << endl;
    }
    assert(ret == ans);
  }
};
