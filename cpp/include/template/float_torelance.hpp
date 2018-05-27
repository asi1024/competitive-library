#include "includes.hpp"

template <typename float_type, const float_type &eps> class float_torelance {
public:
  float_type x;
  float_torelance() { ; }
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

namespace std {
template <typename float_type, const float_type &eps>
float_torelance<float_type, eps> abs(float_torelance<float_type, eps> &x) {
  return float_torelance<float_type, eps>(std::abs(x.x));
}

template <typename float_type, const float_type &eps>
float_torelance<float_type, eps>
sqrt(const float_torelance<float_type, eps> &x) {
  return float_torelance<float_type, eps>(std::sqrt(x.x));
}
}

template <typename float_type, const float_type &eps>
std::istream &operator>>(std::istream &is,
                         float_torelance<float_type, eps> &x) {
  is >> x.x;
  return is;
}

template <typename float_type, const float_type &eps>
std::ostream &operator<<(std::ostream &os,
                         const float_torelance<float_type, eps> &x) {
  os << x.x;
  return os;
}

constexpr long double epsilon11 = 1e-11;
using float11 = float_torelance<long double, epsilon11>;
