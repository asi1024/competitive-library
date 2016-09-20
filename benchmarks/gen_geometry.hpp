#pragma once

#include "testsuite.hpp"

uniform_real_distribution<double> rnd(-100.0, 100.0);

namespace geom_gen {
  using P = Point;
  using S = Segment;
  using L = Line;
  using C = Circle;
  using G = Polygon;
  template<class T> T gen(mt19937 &mt) { assert(false); }
  template<> P gen<P>(mt19937 &mt) { return P(rnd(mt), rnd(mt)); }
  template<> S gen<S>(mt19937 &mt) { return S(gen<P>(mt), gen<P>(mt)); }
  template<> L gen<L>(mt19937 &mt) { return gen<S>(mt); }
  template<> C gen<C>(mt19937 &mt) { return C(gen<P>(mt), rnd(mt)); }
}

template<typename T1, typename T2>
TestSuite<vector<pair<T1, T2>>> random_geometry() {
  mt19937 mt(4);
  TestSuite<vector<pair<T1, T2>>> res;
  for (int i = 0; i < 10; ++i) {
    vector<pair<T1, T2>> query;
    for (int j = 0; j < query_num; ++j) {
      query.emplace_back(geom_gen::gen<T1>(mt), geom_gen::gen<T2>(mt));
    }
    res.add(query, "1000000 queries");
  }
  return res;
}
