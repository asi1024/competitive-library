#pragma once

#include "includes.hpp"

template <typename float_type, const long long inv_eps> class float_torelance {
public:
  static constexpr float_type eps = float_type(1) / inv_eps;
  float_type x;
  float_torelance() : x(0) { ; }
  float_torelance(float_type x_) : x(x_) { ; }
  explicit operator float_type() { return x; }
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

template <typename float_type, const long long inv_eps>
bool isnan(float_torelance<float_type, inv_eps> &x) {
  return std::isnan(x.x);
}

template <typename float_type, const long long inv_eps>
float_torelance<float_type, inv_eps>
abs(float_torelance<float_type, inv_eps> &x) {
  return float_torelance<float_type, inv_eps>(std::abs(x.x));
}

template <typename float_type, const long long inv_eps>
float_torelance<float_type, inv_eps>
sqrt(const float_torelance<float_type, inv_eps> &x) {
  return float_torelance<float_type, inv_eps>(std::sqrt(x.x));
}

template <typename float_type, const long long inv_eps>
float_torelance<float_type, inv_eps>
atan2(const float_torelance<float_type, inv_eps> &x,
      const float_torelance<float_type, inv_eps> &y) {
  return float_torelance<float_type, inv_eps>(std::atan2(x.x, y.x));
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
