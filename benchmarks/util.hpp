#pragma once

#include "../src/Geometry/Geometry.hpp"
#include "../src/Geometry/convex.cpp"
#include "../src/Geometry/distance.cpp"
#include "../src/Geometry/intersect.cpp"
#include "../src/Geometry/intersect_circle.cpp"

#include "../src/Graph/Graph.hpp"
#include "../src/Graph/bfs01.cpp"
#include "../src/Graph/bipartite_matching.cpp"
#include "../src/Graph/dijkstra.cpp"
#include "../src/Graph/lca.cpp"
#include "../src/Graph/max_flow.cpp"
#include "../src/Graph/min_cost_flow.cpp"
#include "../src/Graph/recession.cpp"
#include "../src/Graph/spfa.cpp"

#include "../src/Math/eratosthenes.cpp"
#include "../src/Math/fft.cpp"
#include "../src/Math/matrix.cpp"
#include "../src/Math/mod.cpp"
#include "../src/Math/vector.cpp"

#include "../src/Others/cout.cpp"

#include "../src/String/kmp.cpp"
#include "../src/String/rolling_hash.cpp"

#include "../src/Structure/fenwick_tree.cpp"
#include "../src/Structure/rars.cpp"
#include "../src/Structure/segment_tree.cpp"
#include "../src/Structure/skew_heap.cpp"
#include "../src/Structure/slide_min.cpp"
#include "../src/Structure/starry_sky_tree.cpp"
#include "../src/Structure/unionfind.cpp"

using namespace std;

mt19937 mt(0);
uniform_real_distribution<double> rnd(-100.0, 100.0);

const int array_len = 200000;
const int query_num = 1000000;

// Hash

using ull = unsigned long long;

ull my_hash(const int &n, mt19937 &mt) {
  return ull(n) * ull(mt());
}

ull my_hash(const long long &n, mt19937 &mt) {
  return ull(n) * ull(mt());
}

ull my_hash(const unsigned long long &n, mt19937 &mt) {
  return ull(n) * ull(mt());
}

ull my_hash(const long double &n, mt19937 &mt) {
  return ull(n - 0.123456789) * ull(mt());
}

template<typename T> ull my_hash(const complex<T> &n, mt19937 &mt) {
  return my_hash(real(n), mt) + my_hash(imag(n), mt);
}

template<typename U, typename T> ull my_hash(const pair<U, T> &n, mt19937 &mt) {
  return my_hash(n.first, mt) + my_hash(n.second, mt);
}

template<typename T> ull my_hash(const vector<T> &n, mt19937 &mt) {
  ull sum = 0;
  for (const T &i: n) sum += my_hash(i, mt);
  return sum;
}

template<typename T> ull my_hash(T n) { mt19937 mt(0); return my_hash(n, mt); }

// TestSuite

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
      printf("#%.2d (%s) : %.3f s\n", i, message[i].c_str(), s);
      hash_vec.push_back(my_hash(ret));
    }
    printf("%.3f s\n\n", worst);
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

// STL

TestSuite<vector<int>> random_array() {
  mt19937 mt(1);
  TestSuite<vector<int>> res;
  for (int c = 0; c < 20; ++c) {
    vector<int> ary(200000);
    for (auto &i: ary) i = mt();
    res.add(ary, "Array : len = 200000");
  }
  return res;
}

// Structure

class Query {
public:
  int type, pos, left, right, value;
  Query(int len, int type, mt19937 &mt) :
    type(type),
    pos(mt() % len), left(mt() % len), right(mt() % len),
    value(mt() % 2000 - 1000) {}
};

TestSuite<vector<Query>> random_query() {
  mt19937 mt(2);
  TestSuite<vector<Query>> res;
  for (int i = 0; i < 10; ++i) {
    vector<Query> query;
    for (int j = 0; j < 500000; ++j) {
      query.push_back(Query(0, 200000, mt));
      query.push_back(Query(1, 200000, mt));
    }
    shuffle(begin(query), end(query), mt);
    res.add(query, "500000 update and 500000 find");
  }
  for (int i = 0; i < 5; ++i) {
    vector<Query> query;
    for (int j = 0; j < 1000000; ++j) {
      query.push_back(Query(0, 200000, mt));
    }
    res.add(query, "1000000 find queries");
  }
  for (int i = 0; i < 5; ++i) {
    vector<Query> query;
    for (int j = 0; j < 1000000; ++j) {
      query.push_back(Query(1, 200000, mt));
    }
    res.add(query, "1000000 update queries");
  }
  return res;
}

// Graph

const int vertex_num = 50000;
const int edge_num = 200000;

CGraph<int> random_cgraph(int min_cost, int max_cost) {
  CGraph<int> g(vertex_num);
  for (int i = 0; i < edge_num; ++i) {
    int from = mt() % vertex_num;
    int to = mt() % vertex_num;
    int cost = mt() % (max_cost - min_cost) + min_cost;
    add_edge(g, from, to, cost);
  }
  return g;
}

FGraph<int> random_fgraph(int V, int E, int max_flow) {
  FGraph<int> g(V);
  for (int i = 0; i < E; ++i) {
    int from = mt() % V;
    int to = mt() % V;
    int flow = mt() % max_flow;
    add_edge(g, from, to, flow);
  }
  return g;
}

FCGraph<int, int> random_fcgraph(int V, int E, int max_flow, int max_cost) {
  FCGraph<int, int> g(V);
  for (int i = 0; i < E; ++i) {
    int from = mt() % V;
    int to = mt() % V;
    int flow = mt() % max_flow;
    int cost = mt() % max_cost;
    add_edge(g, from, to, flow, cost);
  }
  return g;
}

Graph random_tree(int V) {
  vector<pair<int,int>> edges;
  for (int i = 1; i < V; ++i) {
    int p = mt() % i;
    if (mt() % 2) edges.emplace_back(i, p);
    else edges.emplace_back(p, i);
  }
  shuffle(begin(edges), end(edges), mt);
  Graph g(V);
  for (auto e: edges) add_edge(g, e.first, e.second);
  return g;
}

// Geometry

template<typename T, T (*f)()>
vector<T> vectorize() {
  vector<T> res;
  for (int i = 0; i < query_num; ++i) res.push_back(f());
  return res;
}

template<typename T>
int zero(T x) { return max(0, min(int(abs(x)), 0)); }

Point random_point() { return Point(rnd(mt), rnd(mt)); }
Segment random_segment() { return Segment(random_point(), random_point()); }
Line random_line() { return Line(random_segment()); }
Circle random_circle() { return Circle(random_point(), rnd(mt)); }
vector<Point> random_points() { return unique(vectorize<Point, random_point>()); }
vector<Segment> random_segments() { return vectorize<Segment, random_segment>(); }
vector<Line> random_lines() { return vectorize<Line, random_line>(); }
vector<Circle> random_circles() { return vectorize<Circle, random_circle>(); }

Polygon random_polygon() {
  Polygon res;
  const ld pi = acos(-1.0);
  for (int i = 0; i < query_num; ++i)
    res.push_back(polar(100.0L, 2 * pi / query_num));
  return res;
}
