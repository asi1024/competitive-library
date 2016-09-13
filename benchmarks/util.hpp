#pragma once

#include "testsuite.hpp"

mt19937 mt(0);
uniform_real_distribution<double> rnd(-100.0, 100.0);

const int array_len = 200000;
const int vertex_num = 50000;
const int edge_num = 200000;

// STL

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

// Structure

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
    for (int j = 0; j < 500000; ++j) {
      query.push_back(Query(array_len, 0, mt));
      query.push_back(Query(array_len, 1, mt));
    }
    shuffle(begin(query), end(query), mt);
    res.add(query, "500000 update and 500000 find");
  }
  for (int i = 0; i < 5; ++i) {
    vector<Query> query;
    for (int j = 0; j < 1000000; ++j) {
      query.push_back(Query(array_len, 0, mt));
    }
    res.add(query, "1000000 find queries");
  }
  for (int i = 0; i < 5; ++i) {
    vector<Query> query;
    for (int j = 0; j < 1000000; ++j) {
      query.push_back(Query(array_len, 1, mt));
    }
    res.add(query, "1000000 update queries");
  }
  return res;
}

// Graph

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
  for (int i = 0; i < 1000000; ++i) res.push_back(f());
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
  for (int i = 0; i < 1000000; ++i)
    res.push_back(polar(100.0L, 2 * pi / 1000000));
  return res;
}
