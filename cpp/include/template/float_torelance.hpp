#pragma once

#include "includes.hpp"

template <typename float_type, const long long inv_eps> class float_torelance {
public:
  static constexpr float_type eps = float_type(1) / inv_eps;
  float_type x;
  float_torelance() : x(0) { ; }
  float_torelance(float_type x_) : x(x_) { ; }
  explicit operator float_type() { return x; }
  template <typename cast_to> explicit operator cast_to() { return cast_to(x); }
  float_torelance operator-() const { return -x; }
  float_torelance operator+(const float_torelance &r) const { return x + r.x; }
  float_torelance operator-(const float_torelance &r) const { return x - r.x; }
  float_torelance operator*(const float_torelance &r) const { return x * r.x; }
  float_torelance operator/(const float_torelance &r) const { return x / r.x; }
  float_torelance &operator+=(const float_torelance &r) {
    x += r.x;
    return *this;
  }
  float_torelance &operator-=(const float_torelance &r) {
    x -= r.x;
    return *this;
  }
  float_torelance &operator*=(const float_torelance &r) {
    x *= r.x;
    return *this;
  }
  float_torelance &operator/=(const float_torelance &r) {
    x /= r.x;
    return *this;
  }
  bool operator<=(const float_torelance &r) const { return x <= r.x + eps; }
  bool operator<(const float_torelance &r) const { return x < r.x - eps; }
  bool operator>=(const float_torelance &r) const { return x >= r.x - eps; }
  bool operator>(const float_torelance &r) const { return x > r.x + eps; }
  bool operator==(const float_torelance &r) const {
    return x - r.x < eps && r.x - x < eps;
  }
  bool operator!=(const float_torelance &r) const {
    return x - r.x > eps || r.x - x > eps;
  }

  float_torelance operator+(const float_type &r) const { return x + r; }
  float_torelance operator-(const float_type &r) const { return x - r; }
  float_torelance operator*(const float_type &r) const { return x * r; }
  float_torelance operator/(const float_type &r) const { return x / r; }
  float_torelance &operator+=(const float_type &r) {
    x += r;
    return *this;
  }
  float_torelance &operator-=(const float_type &r) {
    x -= r;
    return *this;
  }
  float_torelance &operator*=(const float_type &r) {
    x *= r;
    return *this;
  }
  float_torelance &operator/=(const float_type &r) {
    x /= r;
    return *this;
  }
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
};

template <typename U, typename T>
using if_arithmetic_t =
  typename std::enable_if<std::is_arithmetic<U>::value, T>::type;

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, float_torelance<float_type, inv_eps>>
operator+(const lhs_type &l, const float_torelance<float_type, inv_eps> &r) {
  return l + r.x;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, float_torelance<float_type, inv_eps>>
operator-(const lhs_type &l, const float_torelance<float_type, inv_eps> &r) {
  return l - r.x;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, float_torelance<float_type, inv_eps>>
operator*(const lhs_type &l, const float_torelance<float_type, inv_eps> &r) {
  return l * r.x;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, float_torelance<float_type, inv_eps>>
operator/(const lhs_type &l, const float_torelance<float_type, inv_eps> &r) {
  return l / r.x;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, bool>
operator<=(const lhs_type &l, const float_torelance<float_type, inv_eps> &r) {
  return r >= l;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, bool>
operator<(const lhs_type &l, const float_torelance<float_type, inv_eps> &r) {
  return r > l;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, bool>
operator>=(const lhs_type &l, const float_torelance<float_type, inv_eps> &r) {
  return r <= l;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, bool>
operator>(const lhs_type &l, const float_torelance<float_type, inv_eps> &r) {
  return r < l;
}

template <typename lhs_type, typename float_type, const long long inv_eps>
if_arithmetic_t<lhs_type, bool>
operator==(const lhs_type &l, const float_torelance<float_type, inv_eps> &r) {
  return r == l;
}

template <typename float_type, const long long inv_eps>
float_torelance<float_type, inv_eps>
abs(const float_torelance<float_type, inv_eps> &x) {
  return float_torelance<float_type, inv_eps>(std::abs(x.x));
}

template <typename float_type, const long long inv_eps>
float_torelance<float_type, inv_eps>
atan2(const float_torelance<float_type, inv_eps> &x,
      const float_torelance<float_type, inv_eps> &y) {
  return float_torelance<float_type, inv_eps>(std::atan2(x.x, y.x));
}

template <typename float_type, const long long inv_eps>
bool copysign(const float_torelance<float_type, inv_eps> &x,
              const float_torelance<float_type, inv_eps> &y) {
  return std::copysign(x.x, y.x);
}

template <typename float_type, const long long inv_eps>
bool isfinite(const float_torelance<float_type, inv_eps> &x) {
  return std::isfinite(x.x);
}

template <typename float_type, const long long inv_eps>
bool isinf(const float_torelance<float_type, inv_eps> &x) {
  return std::isinf(x.x);
}

template <typename float_type, const long long inv_eps>
bool isnan(const float_torelance<float_type, inv_eps> &x) {
  return std::isnan(x.x);
}

template <typename float_type, const long long inv_eps>
bool fabs(const float_torelance<float_type, inv_eps> &x) {
  return std::fabs(x.x);
}

template <typename float_type, const long long inv_eps>
bool hypot(const float_torelance<float_type, inv_eps> &x,
           const float_torelance<float_type, inv_eps> &y) {
  return std::hypot(x.x, y.x);
}

template <typename float_type, const long long inv_eps>
bool scalbn(const float_torelance<float_type, inv_eps> &x, const int exp) {
  return std::scalbn(x.x, exp);
}

template <typename float_type, const long long inv_eps>
float_torelance<float_type, inv_eps>
sqrt(const float_torelance<float_type, inv_eps> &x) {
  return float_torelance<float_type, inv_eps>(std::sqrt(x.x));
}

template <typename float_type, const long long inv_eps>
std::istream &operator>>(std::istream &is,
                         float_torelance<float_type, inv_eps> &x) {
  is >> x.x;
  return is;
}

template <typename float_type, const long long inv_eps>
std::ostream &operator<<(std::ostream &os,
                         const float_torelance<float_type, inv_eps> &x) {
  os << x.x;
  return os;
}

using float11 = float_torelance<long double, 100000000000LL>;
