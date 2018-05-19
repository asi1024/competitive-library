#pragma once

#include "../template/const_value.hpp"
#include "../template/includes.hpp"

template <class edge_t> class graph_t {
  std::vector<std::vector<edge_t>> g;

public:
  using reference = std::vector<edge_t> &;
  using const_reference = const std::vector<edge_t> &;
  using iterator = typename std::vector<edge_t>::iterator;
  graph_t() : g(0) { ; }
  graph_t(int n) : g(n) { ; }
  int size() const { return g.size(); }
  void push_back(const std::vector<edge_t> &es) { g.push_back(es); }
  reference operator[](int x) { return g[x]; }
  const_reference operator[](int x) const { return g[x]; }
  iterator &begin() { return begin(g); }
  iterator &end() { return end(g); }
};

template <typename edge_t, class... Args>
void add_edge(graph_t<edge_t> &g, int from, int to, Args... args) {
  g[from].emplace_back(from, to, args...);
}

template <typename edge_t, class... Args>
void add_edge(graph_t<edge_t> &g, int from, int to,
         typename edge_t::capacity_type cap, Args... args) {
  g[from].emplace_back(from, to, (int)g[to].size(), cap, args...);
  g[to].emplace_back(to, from, (int)g[from].size() - 1,
                     zero<typename edge_t::capacity_type>(), args...);
}
