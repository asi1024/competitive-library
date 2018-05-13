#pragma once

#include "../util.hpp"

template<class edge_t>
class graph_t {
  std::vector<std::vector<edge_t>> g;
public:
  using reference = std::vector<edge_t>&;
  using const_reference = const std::vector<edge_t>&;
  using iterator = typename std::vector<edge_t>::iterator;
  graph_t() : g(0) {;}
  graph_t(int n) : g(n) {;}
  int size() const { return g.size(); }
  void push_back(const vector<edge_t> &es) { g.push_back(es); }
  template<class... Args>
  void add(int from, int to, Args... args) {
    g[from].emplace_back(from, to, args...);
  }
  template<class... Args>
  void biadd(int from, int to, Args... args) {
    g[from].emplace_back(from, to, args...);
    g[to].emplace_back(to, from, args...);
  }
  reference operator[](int x) { return g[x]; }
  const_reference operator[](int x) const { return g[x]; }
  iterator &begin() { return begin(g); }
  iterator &end() { return end(g); }
};
