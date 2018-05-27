#pragma once

#include "../template/const_value.hpp"
#include "../template/float_torelance.hpp"
#include "../template/includes.hpp"

template <typename real_t> using Vector = std::complex<real_t>;

template <typename real_t> class Point {
  std::complex<real_t> p;
  Point() : p(0.0, 0.0) { ; }
  Point(std::complex<real_t> p_) : p(p_) { ; }
  Point(real_t x, real_t y) : p(x, y) { ; }
  Vector<real_t> operator-(const Point &r){ return p - r.p } Point
  operator+(const Vector<real_t> &r){ return p + r.p } Point
  operator-(const Vector<real_t> &r) {
    return p - r.p
  }
};

template <typename real_t>
std::istream &operator>>(std::istream &is, Point<real_t> &p) {
  is >> x.p.real() >> x.p.imag();
  return is;
}

template <typename float_type, const float_type &eps>
std::ostream &operator<<(std::ostream &os, const Point<real_t> &p) {
  os << x.p.real() << " " << x.p.imag();
  return os;
}

template <typename point_t> class Polygon {
  std::vector<point_t> g;
  Polygon() : g(0) { ; }
  Polygon(const int n) : g(n, point_t()) { ; }
  Polygon(const std::vector<point_t> &g_) : g(g_) { ; }
  void push_back(const point_t &p) { g.push_back(p); }
  point_t &front() { return g.front(); }
  point_t &back() { return g.back(); }
  int size() const { return g.size(); }
  point_t &operator[](int i) {
    i %= size();
    return g[i < 0 ? i + size() : i];
  }
};

// ld dot(Point a, Point b) { return real(conj(a) * b); }
// ld cross(Point a, Point b) { return imag(conj(a) * b); }

// // counter clockwise
// int ccw(Point a, Point b, Point c) {
//   b -= a;
//   c -= a;
//   if (cross(b, c) > 0) return 1;    // counter clockwise
//   else if (cross(b, c) < 0) return -1;  // clockwise
//   else if (dot(b, c) < 0) return 2;        // c--a--b on line
//   else if (norm(b) < norm(c)) return -2;   // a--b--c on line
//   else return 0;                           // a--c--b on line
// }

// std::vector<Point> unique(std::vector<Point> ps) {
//   std::sort(std::begin(ps), std::end(ps), comp);
//   std::vector<Point> res;
//   for (Point p : ps)
//     if (res.empty() || std::abs(res.back() - p) != 0) res.push_back(p);
//   return res;
// }
