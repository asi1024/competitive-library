#pragma once

#include "../template/const_value.hpp"
#include "../template/float_torelance.hpp"
#include "../template/includes.hpp"

template <typename real_t> using Vector = std::complex<real_t>;

template <typename real_t> class Point {
public:
  std::complex<real_t> p;
  Point() : p(0.0, 0.0) { ; }
  explicit Point(std::complex<real_t> p_) : p(p_) { ; }
  Point(real_t x, real_t y) : p(x, y) { ; }
  Vector<real_t> operator-(const Point &r) const { return p - r.p; }
  Point operator+(const Vector<real_t> &r) const { return Point(p + r); }
  Point operator-(const Vector<real_t> &r) const { return Point(p - r); }
  real_t x() const { return p.real(); }
  real_t y() const { return p.imag(); }
};

template <typename real_t>
std::istream &operator>>(std::istream &is, Point<real_t> &p) {
  real_t x, y;
  is >> x >> y;
  p = Point<real_t>(x, y);
  return is;
}

template <typename real_t>
std::ostream &operator<<(std::ostream &os, const Point<real_t> &p) {
  os << p.p.real() << " " << p.p.imag();
  return os;
}

// template <typename point_t> class Polygon {
//   std::vector<point_t> g;
//   Polygon() : g(0) { ; }
//   Polygon(const int n) : g(n, point_t()) { ; }
//   Polygon(const std::vector<point_t> &g_) : g(g_) { ; }
//   void push_back(const point_t &p) { g.push_back(p); }
//   point_t &front() { return g.front(); }
//   point_t &back() { return g.back(); }
//   int size() const { return g.size(); }
//   point_t &operator[](int i) {
//     i %= size();
//     return g[i < 0 ? i + size() : i];
//   }
// };

template <typename real_t> real_t dot(Vector<real_t> a, Vector<real_t> b) {
  return std::real(std::conj(a) * b);
}
template <typename real_t> real_t cross(Vector<real_t> a, Vector<real_t> b) {
  return std::imag(std::conj(a) * b);
}

// counter clockwise
template <typename real_t> int ccw(const Point<real_t> &a, const Point<real_t> &b, const Point<real_t> &c) {
  Vector<real_t> base = b - a, target = c - a;
  if (cross(base, target) > 0) return 1;     // counter clockwise
  if (cross(base, target) < 0) return -1;    // clockwise
  if (dot(base, target) < 0) return 2;       // c--a--b on line
  if (norm(base) < norm(target)) return -2;  // a--b--c on line
  return 0;                                  // a--c--b on line
}

// std::vector<Point> unique(std::vector<Point> ps) {
//   std::sort(std::begin(ps), std::end(ps), comp);
//   std::vector<Point> res;
//   for (Point p : ps)
//     if (res.empty() || std::abs(res.back() - p) != 0) res.push_back(p);
//   return res;
// }
