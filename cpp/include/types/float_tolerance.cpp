#pragma once

#include "../template/includes.hpp"

template <typename float_type, const long long inv_eps> class float_tolerance {
  void init() {
    static_assert(std::is_floating_point<float_type>::value,
                  "float_type must be real number");
    static_assert(inv_eps >= 1000, "Too large tolerance");
  }

public:
  static constexpr float_type eps = float_type(1) / inv_eps;
  float_type x;
  float_tolerance() : x(0) { init(); }
  float_tolerance(float_type x_) : x(x_) { init(); }
  explicit operator float_type() { return x; }
  template <typename cast_to> explicit operator cast_to() { return cast_to(x); }
  float_tolerance operator-() const { return -x; }
  float_tolerance operator+(const float_type &r) const { return x + r; }
  float_tolerance operator-(const float_type &r) const { return x - r; }
  float_tolerance operator*(const float_type &r) const { return x * r; }
  float_tolerance operator/(const float_type &r) const { return x / r; }
  float_tolerance &operator+=(const float_type &r) { return x += r, *this; }
  float_tolerance &operator-=(const float_type &r) { return x -= r, *this; }
  float_tolerance &operator*=(const float_type &r) { return x *= r, *this; }
  float_tolerance &operator/=(const float_type &r) { return x /= r, *this; }
  bool operator<=(const float_type &r) const { return x <= r + eps; }
  bool operator<(const float_type &r) const { return x < r - eps; }
  bool operator>=(const float_type &r) const { return x >= r - eps; }
  bool operator>(const float_type &r) const { return x > r + eps; }
  bool operator==(const float_type &r) const {
    return x - r < eps && r - x < eps;
  }
  bool operator!=(const float_type &r) const {
    return x - r > eps || r - x > eps;
  }
  float_tolerance operator+(const float_tolerance &r) const { return x + r.x; }
  float_tolerance operator-(const float_tolerance &r) const { return x - r.x; }
  float_tolerance operator*(const float_tolerance &r) const { return x * r.x; }
  float_tolerance operator/(const float_tolerance &r) const { return x / r.x; }
  float_tolerance &operator+=(const float_tolerance &r) { return *this += r.x; }
  float_tolerance &operator-=(const float_tolerance &r) { return *this -= r.x; }
  float_tolerance &operator*=(const float_tolerance &r) { return *this *= r.x; }
  float_tolerance &operator/=(const float_tolerance &r) { return *this /= r.x; }
  bool operator<=(const float_tolerance &r) const { return *this <= r.x; }
  bool operator<(const float_tolerance &r) const { return *this < r.x; }
  bool operator>=(const float_tolerance &r) const { return *this >= r.x; }
  bool operator>(const float_tolerance &r) const { return *this > r.x; }
  bool operator==(const float_tolerance &r) const { return *this == r.x; }
  bool operator!=(const float_tolerance &r) const { return *this != r.x; }
};

template <typename U, typename T>
using if_arithmetic_t =
  typename std::enable_if<std::is_arithmetic<U>::value, T>::type;

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, float_tolerance<float_type, inv_eps>>
operator+(const lhs_type &l, const float_tolerance<float_type, inv_eps> &r) {
  return static_cast<float_type>(l) + r.x;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, float_tolerance<float_type, inv_eps>>
operator-(const lhs_type &l, const float_tolerance<float_type, inv_eps> &r) {
  return static_cast<float_type>(l) - r.x;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, float_tolerance<float_type, inv_eps>>
operator*(const lhs_type &l, const float_tolerance<float_type, inv_eps> &r) {
  return static_cast<float_type>(l) * r.x;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, float_tolerance<float_type, inv_eps>>
operator/(const lhs_type &l, const float_tolerance<float_type, inv_eps> &r) {
  return static_cast<float_type>(l) / r.x;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, bool>
operator<=(const lhs_type &l, const float_tolerance<float_type, inv_eps> &r) {
  return r >= l;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, bool>
operator<(const lhs_type &l, const float_tolerance<float_type, inv_eps> &r) {
  return r > l;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, bool>
operator>=(const lhs_type &l, const float_tolerance<float_type, inv_eps> &r) {
  return r <= l;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, bool>
operator>(const lhs_type &l, const float_tolerance<float_type, inv_eps> &r) {
  return r < l;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, bool>
operator==(const lhs_type &l, const float_tolerance<float_type, inv_eps> &r) {
  return r == l;
}

template <typename float_type, const long long inv_eps>
float_tolerance<float_type, inv_eps>
abs(const float_tolerance<float_type, inv_eps> &x) {
  return std::abs(x.x);
}

template <typename float_type, const long long inv_eps>
float_tolerance<float_type, inv_eps>
atan2(const float_tolerance<float_type, inv_eps> &x,
      const float_tolerance<float_type, inv_eps> &y) {
  return std::atan2(x.x, y.x);
}

template <typename float_type, const long long inv_eps>
bool copysign(const float_tolerance<float_type, inv_eps> &x,
              const float_tolerance<float_type, inv_eps> &y) {
  return std::copysign(x.x, y.x);
}

template <typename float_type, const long long inv_eps>
bool isfinite(const float_tolerance<float_type, inv_eps> &x) {
  return std::isfinite(x.x);
}

template <typename float_type, const long long inv_eps>
bool isinf(const float_tolerance<float_type, inv_eps> &x) {
  return std::isinf(x.x);
}

template <typename float_type, const long long inv_eps>
bool isnan(const float_tolerance<float_type, inv_eps> &x) {
  return std::isnan(x.x);
}

template <typename float_type, const long long inv_eps>
float_tolerance<float_type, inv_eps>
sqrt(const float_tolerance<float_type, inv_eps> &x) {
  return std::sqrt(x.x);
}

template <typename float_type, const long long inv_eps>
std::istream &operator>>(std::istream &is,
                         float_tolerance<float_type, inv_eps> &x) {
  is >> x.x;
  return is;
}

template <typename float_type, const long long inv_eps>
std::ostream &operator<<(std::ostream &os,
                         const float_tolerance<float_type, inv_eps> &x) {
  os << x.x;
  return os;
}

using float11 = float_tolerance<long double, 100000000000LL>;
