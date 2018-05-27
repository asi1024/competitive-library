#include "Geometry.hpp"
#include "distance.cpp"
#include "intersect.cpp"

template <typename real_t>
struct Circle {
  Point<real_t> p;
  real_t r;
  Circle(const Point<real_t> &p_, real_t r_) : p(p_), r(r_) { ; }
};

template <typename real_t>
std::vector<Point<real_t>> is_cc(const Circle<real_t> &c1, const Circle<real_t> &c2) {
  std::vector<Point<real_t>> res;
  real_t d = abs(c1.p - c2.p);
  real_t rc = (d * d + c1.r * c1.r - c2.r * c2.r) / (2 * d);
  real_t dfr = c1.r * c1.r - rc * rc;
  if (abs(dfr) <= 0)
    dfr = 0.0;
  else if (dfr < 0.0)
    return res;  // no intersection
  real_t rs = sqrt(dfr);
  Vector<real_t> diff = (c2.p - c1.p) / d;
  res.push_back(c1.p + diff * Point<real_t>(rc, rs));
  if (dfr != 0.0) res.push_back(c1.p + diff * Point<real_t>(rc, -rs));
  return res;
}

template <typename real_t>
std::vector<Point<real_t>> is_cl(const Circle<real_t> &c, const Line<real_t> &l) {
  std::vector<Point<real_t>> res;
  real_t d = dist_lp(l, c.p);
  if (d <= c.r) {
    real_t len = (d > c.r) ? 0.0 : sqrt(c.r * c.r - d * d);  // safety;
    Vector<real_t> nor = (l.a - l.b) / abs(l.a - l.b);
    res.push_back(proj(l, c.p) + len * nor);
    if (len != 0.0) res.push_back(proj(l, c.p) - len * nor);
  }
  return res;
}

template <typename real_t>
std::vector<Point<real_t>> is_cs(const Circle<real_t> &c, const Segment<real_t> &s) {
  std::vector<Point<real_t>> v = is_cl(c, Line<real_t>(s)), res;
  for (Point<real_t> p : v)
    if (isis_sp(s, p)) res.push_back(p);
  return res;
}
