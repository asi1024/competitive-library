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

template <typename T> struct is_bidirectional {
  struct Fallback {
    int from;
  };
  struct Derived : T, Fallback {};
  template <typename C, C> struct ChT;
  template <typename C> static char (&f(ChT<int Fallback::*, &C::from> *))[1];
  template <typename C> static char (&f(...))[2];
  static bool const value = sizeof(f<Derived>(0)) == 2;
};

// template <class T> class has_capacity {
//   template <class U>
//   static constexpr bool check(typename U::capacity_type *) { return true; }
//   template <class U>
//   static constexpr bool check(...) { return false; }
// public:
//   static constexpr bool value = check<T>(nullptr);
// };

template <typename edge_t, class... Args>
typename std::enable_if<!is_bidirectional<edge_t>::value, void>::type
add_edge(graph_t<edge_t> &g, int from, int to, Args... args) {
  g[from].emplace_back(from, to, args...);
}

template <typename edge_t, class... Args>
typename std::enable_if<is_bidirectional<edge_t>::value, void>::type
add_edge(graph_t<edge_t> &g, int from, int to, Args... args) {
  g[from].emplace_back(from, to, args...);
  g[to].emplace_back(to, from, args...);
}

template <typename edge_t>
void add_edge(graph_t<edge_t> &g, int from, int to,
              typename edge_t::capacity_type cap) {
  g[from].emplace_back(from, to, (int)g[to].size(), cap);
  g[to].emplace_back(to, from, (int)g[from].size() - 1,
                     zero<typename edge_t::capacity_type>());
}

template <typename edge_t>
void add_edge(graph_t<edge_t> &g, int from, int to,
              typename edge_t::capacity_type cap,
              typename edge_t::cost_type cost) {
  g[from].emplace_back(from, to, (int)g[to].size(), cap, cost);
  g[to].emplace_back(to, from, (int)g[from].size() - 1,
                     zero<typename edge_t::capacity_type>(), -cost);
}
