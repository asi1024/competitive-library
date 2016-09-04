#pragma once

#include "../util.hpp"

struct Edge {
  int to;
  Edge(int t) : to(t) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to) {
  g[from].push_back(to);
}


struct Edge2 {
  int from, to;
  Edge2(int s, int t) : from(s), to(t) {}
};

using Graph2 = vector<vector<Edge2>>;

void add_edge(Graph2 &g, int from, int to) {
  g[from].emplace_back(from, to);
}


template <typename Cost>
struct CEdge {
  int from, to;
  Cost cost;
  CEdge(int s, int t, Cost c) : from(s), to(t), cost(c) {}
};

template<typename Cost> using CGraph = vector<vector<CEdge<Cost>>>;

template <typename Cost>
void add_edge(CGraph<Cost> &g, int from, int to, Cost cost) {
  g[from].emplace_back(from, to, cost);
}


template <typename Flow>
struct FEdge {
  int from, to;
  Flow cap; int rev;
  FEdge(int s, int t, Flow f, int r) : from(s), to(t), cap(f), rev(r) {}
};

template<typename Flow> using FGraph = vector<vector<FEdge<Flow>>>;

template <typename Flow>
void add_edge(FGraph<Flow> &g, int from, int to, Flow cap) {
  g[from].emplace_back(from, to, cap, (int)g[to].size());
  g[to].emplace_back(to, from, 0, (int)g[from].size() - 1);
}


template <typename Flow, typename Cost>
struct FCEdge {
  int from, to;
  Flow cap; int rev;
  Cost cost;
  FCEdge(int s, int t, Flow f, int r, Cost c) :
    from(s), to(t), cap(f), rev(r), cost(c) {}
};

template<typename Flow, typename Cost>
using FCGraph = vector<vector<FCEdge<Flow, Cost>>>;

template <typename Flow, typename Cost>
void add_edge(FCGraph<Flow, Cost> &g, int from, int to, Flow cap, Cost cost) {
  g[from].emplace_back(from, to, cap, (int)g[to].size(), cost);
  g[to].emplace_back(to, from, 0, (int)g[from].size() - 1, -cost);
}
