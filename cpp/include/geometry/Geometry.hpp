#pragma once

#include "../template/const_value.hpp"
#include "../template/float_tolerance.hpp"
#include "../template/includes.hpp"

template <typename real_t> using Vector = std::complex<real_t>;

template <typename float_type, const long long inv_eps>
float_tolerance<float_type, inv_eps>
abs(const Vector<float_tolerance<float_type, inv_eps>> &x) {
  return sqrt(std::norm(x));
}

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
  bool operator==(const Point &r) const { return abs(p - r.p) <= 0; }
  bool operator!=(const Point &r) const { return abs(p - r.p) > 0; }
  bool operator<(const Point &r) const {
    return x() < r.x() || (x() <= r.x() && y() < r.y());
  }
  bool operator<=(const Point &r) const {
    return x() < r.x() || (x() <= r.x() && y() <= r.y());
  }
  bool operator>(const Point &r) const {
    return x() > r.x() || (x() >= r.x() && y() > r.y());
  }
  bool operator>=(const Point &r) const {
    return x() > r.x() || (x() >= r.x() && y() >= r.y());
  }
};

template <typename real_t, typename ratio_t = real_t>
Point<real_t> average(const Point<real_t> &p1, const Point<real_t> &p2,
                      const ratio_t &r1 = 1, const ratio_t &r2 = 1) {
  const real_t ratio1 = r1, ratio2 = r2;
  return Point<real_t>((p1.p * ratio1 + p2.p * ratio2) / (ratio1 + ratio2));
}

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

template <typename real_t>
real_t dot(const Vector<real_t> &a, const Vector<real_t> &b) {
  return std::real(std::conj(a) * b);
}
template <typename real_t>
real_t cross(const Vector<real_t> &a, const Vector<real_t> &b) {
  return std::imag(std::conj(a) * b);
}

template <typename real_t>
int ccw(const Point<real_t> &a, const Point<real_t> &b,
        const Point<real_t> &c) {
  Vector<real_t> base = b - a, target = c - a;
  if (cross(base, target) > 0) return 1;     // counter clockwise
  if (cross(base, target) < 0) return -1;    // clockwise
  if (dot(base, target) < 0) return 2;       // c--a--b on line
  if (norm(base) < norm(target)) return -2;  // a--b--c on line
  return 0;                                  // a--c--b on line
}
