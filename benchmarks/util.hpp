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

class Timer {
  double start;
public:
  Timer() : start(clock()) {}
  double stop() { return (clock() - start) / CLOCKS_PER_SEC; }
};

void print(const char *name, double t, double x) {
  t = (t + 2 * x) * 1e9;
  printf("%s : %.3f ns\n", name, t);
  // printf("%s : %.3f ns (%.3f ns - %.3f ns)\n", name, t, t - 2 * x, t + 2 * x);
}

void check(double (*f)(), const char *name) {
  const int N = 5;
  vector<double> res(N);
  for (auto &i: res) i = f();
  double ave = accumulate(begin(res), end(res), 0.0) / N; 
  transform(begin(res), end(res), begin(res), [&](double x){ return pow(x - ave, 2); });
  double sd = sqrt(accumulate(begin(res), end(res), 0.0) / N);
  print(name, ave, sd);
}

mt19937 mt(0);
uniform_real_distribution<double> rnd(-100.0, 100.0);

const int array_len = 200000;
const int query_num = 1000000;

// STL

vector<int> random_array() {
  vector<int> res(array_len);
  for (auto &i: res) i = mt();
  return res;
}

// Structure

class Query {
public:
  int type, pos, left, right, value;
  Query(int len) :
    type(mt() % 2),
    pos(mt() % len), left(mt() % len), right(mt() % len),
    value(mt() % 2000 - 1000)
  {
    if (left > right) swap(left, right);
    ++right;
  }
};

vector<Query> random_query() {
  vector<Query> res(query_num, array_len);
  for (auto &i: res) i = Query(array_len);
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

template<typename T, T (*f)()>
vector<T> vectorize() {
  vector<T> res;
  for (int i = 0; i < query_num; ++i) res.push_back(f());
  return res;
}

Point random_point() { return Point(rnd(mt), rnd(mt)); }
Segment random_segment() { return Segment(random_point(), random_point()); }
Line random_line() { return Line(random_segment()); }
Circle random_circle() { return Circle(random_point(), rnd(mt)); }
vector<Point> random_points() { return vectorize<Point, random_point>(); }
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
