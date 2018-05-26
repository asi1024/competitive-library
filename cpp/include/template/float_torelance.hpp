#include "includes.hpp"

template <typename float_type, const float_type &eps> class float_torelance {
  float_type x;
public:
  float_torelance() { ; }
  float_torelance(float_type value) : x(value) { ; }
  float_type &value() { return x; }
  float_torelance operator+(const float_torelance &r) { return x + r.x; }
  float_torelance operator-(const float_torelance &r) { return x - r.x; }
  float_torelance operator*(const float_torelance &r) { return x * r.x; }
  float_torelance operator/(const float_torelance &r) { return x / r.x; }
  float_torelance &operator+=(const float_torelance &r) { return x += r.x; }
  float_torelance &operator-=(const float_torelance &r) { return x -= r.x; }
  float_torelance &operator*=(const float_torelance &r) { return x *= r.x; }
  float_torelance &operator/=(const float_torelance &r) { return x /= r.x; }
  bool operator<=(const float_torelance &r) { return x <= r.x + eps; }
  bool operator<(const float_torelance &r) { return x < r.x - eps; }
  bool operator>=(const float_torelance &r) { return x >= r.x - eps; }
  bool operator>(const float_torelance &r) { return x > r.x + eps; }
  bool operator==(const float_torelance &r) {
    return x - r.x < eps && r.x - x < eps;
  }
};

template <typename float_type, const float_type &eps>
std::istream &operator>>(std::istream &is, float_torelance<float_type, eps> x) {
  is >> x.value();
  return is;
}

template <typename float_type, const float_type &eps>
std::ostream &operator<<(std::ostream &os, float_torelance<float_type, eps> x) {
  os << x;
  return os;
}

constexpr long double epsilon11 = 1e-11;
using float11 = float_torelance<long double, epsilon11>;
