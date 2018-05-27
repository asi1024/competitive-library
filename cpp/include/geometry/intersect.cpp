#pragma once

#include "Geometry.hpp"

template <typename real_t> struct Segment {
  Point<real_t> a, b;
  Segment(const Point<real_t> &p, const Point<real_t> &q) : a(p), b(q) { ; }
};

template <typename real_t> struct Line {
  Point<real_t> a, b;
  Line(const Point<real_t> &p, const Point<real_t> &q) : a(p), b(q) { ; }
  explicit Line(const Segment<real_t> &s) : a(s.a), b(s.b) { ; }
};

template <typename real_t>
bool isis_ll(const Line<real_t> &l, const Line<real_t> &m) {
  return std::abs(cross(l.b - l.a, m.b - m.a)) > 0;
}

// bool isis_ls(Line l, Segment s) {
//   ld a = cross(l.b - l.a, s.a - l.a);
//   ld b = cross(l.b - l.a, s.b - l.a);
//   return (a * b < 0);
// }

// bool isis_lp(Line l, Point p) { return abs(cross(l.b - p, l.a - p)) <= 0; }

// bool isis_ss(Segment s, Segment t) {
//   return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
//          ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
// }

// bool isis_sp(Segment s, Point p) {
//   return abs(s.a - p) + abs(s.b - p) - abs(s.b - s.a) < 0;
// }

template <typename real_t>
Point<real_t> proj(const Line<real_t> &l, const Point<real_t> &p) {
  real_t t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
  return l.a + t * (l.a - l.b);
}

// Point mirror(Line l, Point p) { return (ld)2 * proj(l, p) - p; }

// Point is_ll(Line s, Line t) {
//   Point sv = s.b - s.a, tv = t.b - t.a;
//   return s.a + sv * cross(tv, t.a - s.a) / cross(tv, sv);
// }
