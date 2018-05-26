template <typename float_type, const float_type &eps> class float_torelance {
  float_type x;

public:
  float_torelance(float_type value) : x(value) { ; }
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

constexpr long double epsilon11 = 1e-11;
using real = float_torelance<long double, epsilon11>;
