#pragma once

#include "intersect.cpp"

template <typename real_t> class Polygon {
  using point_t = Point<real_t>;

public:
  std::vector<point_t> g;
  Polygon() : g(0) { ; }
  Polygon(const int n) : g(n, point_t()) { ; }
  Polygon(const std::vector<point_t> &g_) : g(g_) { ; }
  void push_back(const point_t &p) { g.push_back(p); }
  point_t &front() { return g.front(); }
  point_t &back() { return g.back(); }
  int size() const { return g.size(); }
  void resize(int n) { g.resize(n); }
  point_t &operator[](int i) {
    i %= size();
    return g[i < 0 ? i + size() : i];
  }
  const point_t &operator[](int i) const {
    i %= size();
    return g[i < 0 ? i + size() : i];
  }
};

template <typename real_t> real_t area(const Polygon<real_t> &g) {
  real_t res = 0;
  int n = g.size();
  for (int i = 0; i < n; ++i) {
    res += cross(g[i].p, g[i + 1].p);
  }
  return res / 2;
}

template <typename real_t>
int is_in_polygon(const Polygon<real_t> &g, const Point<real_t> &p) {
  // in  ->  1
  // on  ->  0
  // out -> -1
  int n = g.size();
  real_t sum = 0;
  for (int i = 0; i < n; i++) {
    if (isis_sp(Segment<real_t>(g[i], g[i + 1]), p)) return 0;  // on
    sum += arg((g[i + 1] - p) / (g[i] - p));
  }
  return abs(sum) > 0.5 ? 1 : -1;
}
