#pragma once

#include "../util.hpp"

/*
template <typename Weight>
struct Edge{
  int from, to; Weight cost;
  Edge(int s, int t, Weight c) : from(s), to(t), cost(c) {}
};
*/

using Flow = int;

template <typename Weight>
struct Edge{
  int from, to;
  Flow cap; int rev;
  Weight cost;
  Edge(int t) : to(t) {}
  Edge(int s, int t) : from(s), to(t) {}
  Edge(int s, int t, Weight c) : from(s), to(t), cost(c) {}
  Edge(int s, int t, Flow f, int r) :
    from(s), to(t), cap(f), rev(r) {}
  Edge(int s, int t, Flow f, int r, Weight c) :
    from(s), to(t), cap(f), rev(r), cost(c) {}
};

template <typename Weight> using Edges = vector<Edge<Weight>>;
template <typename Weight> using Graph = vector<Edges<Weight>>;
template <typename Weight> using Array = vector<Weight>;

/*
template <typename Weight>
void add_edge(Graph<Weight> &g, int from, int to) {
  g[from].push_back(Edge<Weight>(to));
}
*/

template <typename Weight>
void add_edge(Graph<Weight> &g, int from, int to) {
  g[from].push_back(Edge<Weight>(from, to));
}

template <typename Weight>
void add_edge(Graph<Weight> &g, int from, int to, Weight cost) {
  g[from].push_back(Edge<Weight>(from, to, cost));
}

template <typename Weight>
void add_edge(Graph<Weight> &g, int from, int to, Flow cap) {
  g[from].emplace_back(from, to, cap, (int)g[to].size());
  g[to].emplace_back(to, from, 0, (int)g[from].size() - 1);
}

template <typename Weight>
void add_edge(Graph<Weight> &g, int from, int to, Flow cap, Weight cost) {
  g[from].push_back(Edge<Weight>(from, to, cap, (int)g[to].size(), cost));
  g[to].push_back(Edge<Weight>(to, from, 0, (int)g[from].size() - 1, -cost));
}
