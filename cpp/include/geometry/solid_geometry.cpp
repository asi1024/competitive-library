// Google Code Jam 2018 Qual D

#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

class GoogleCodeJam {
  int case_id;
public:
  void exec() const;
  GoogleCodeJam() {
    int T;
    cin >> T;
    for (case_id = 1; case_id <= T; ++case_id) {
      cout << "Case #" << case_id << ":" << endl;
      exec();
    }
  }
};

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha;
  cout.imbue(loc);
  cout << setprecision(16) << fixed;
  GoogleCodeJam();
  return 0;
}

// ======= exec =======

using ld = long double;
const ld eps = 1e-8, inf = 1e12;

template<int D>
class PointND {
  template<class Func> PointND unop(Func f) const {
    array<ld, D> res;
    transform(begin(x), end(x), begin(res), f);
    return PointND(res);
  }
  template<class Func> PointND iunop(Func f) {
    transform(begin(x), end(x), begin(x), f);
  }
  template<class Func> PointND binop(Func f, const PointND &r) const {
    array<ld, D> res;
    transform(begin(x), end(x), begin(r.x), begin(res), f);
    return PointND(res);
  }
  template<class Func> void ibinop(Func f, const PointND &r) {
    transform(begin(x), end(x), begin(r.x), begin(x), f);
  }
public:
  array<ld, D> x;
  PointND(array<ld, D> x) : x(x) {;}
  ld &operator[](int i) { return x[i]; }
  const ld &operator[](int i) const { return x[i]; }
  PointND operator-() const { return unop(negate<ld>()); }
  PointND operator+(const PointND &r) const { return binop(plus<ld>(), r); }
  PointND operator+=(const PointND &r) { ibinop(plus<ld>(), r); return *this; }
  PointND operator-(const PointND &r) const { return binop(minus<ld>(), r); }
  PointND operator-=(const PointND &r) { ibinop(minus<ld>(), r); return *this; }
  PointND operator*(const ld &r) const { return unop([&](ld x) { return x * r; }); }
  PointND operator*=(const ld &r) { iunop([&](ld x) { return x * r; }); return *this; }
  PointND operator/(const ld &r) const { return unop([&](ld x) { return x / r; }); }
  PointND operator/=(const ld &r) { iunop([&](ld x) { return x / r; }); return *this; }
  ld dot(const PointND &r) const {
    PointND v = binop(multiplies<ld>(), r);
    return accumulate(begin(v.x), end(v.x), 0.0L);
  }
  ld norm() const { return dot(*this); }
  ld abs() const { return sqrt(norm()); }
};

template<int D> ld dot(const PointND<D> &a, const PointND <D>&b) { return a.dot(b); }
template<int D> ld norm(const PointND<D> &a) { return a.norm(); }
template<int D> ld abs(const PointND<D> &a) { return a.abs(); }

template<int D>
ostream& operator<<(ostream &os, PointND<D> p) {
  os << "(";
  for (int i = 0; i < D; i++) {
    if (i > 0) os << ", ";
    os << p[i];
  }
  os << ")";
  return os;
}

// 3D Geometry

using Point3D = PointND<3>;

Point3D cross(const Point3D &l, const Point3D &r) {
  const ld x = l[1] * r[2] - l[2] * r[1];
  const ld y = l[2] * r[0] - l[0] * r[2];
  const ld z = l[0] * r[1] - l[1] * r[0];
  return Point3D({ x, y, z });
}
ld volume(const Point3D &a, const Point3D &b, const Point3D &c) {
  return abs(dot(cross(a, b), c));
}
  
struct Segment3D {
  Point3D a, b;
  Segment3D(const Point3D &a, const Point3D &b) : a(a), b(b) {;}
};

bool is_in_segment(const Segment3D &s, const Point3D &p) {
  s.a - p;
  return abs(abs(s.a - p) + abs(s.b - p) - abs(s.a - s.b)) < eps;
}

Point3D project_lp(const Segment3D &s, Point3D &p) {
  Point3D point = s.a, vec = s.b - s.a;
  return point + vec * dot(p - point, vec) / norm(vec);
}

// Quaternion

using Quaternion = PointND<4>;

Quaternion conj(const Quaternion &x) { return Quaternion({ x[0], -x[1], -x[2], -x[3] }); }

Quaternion operator*(const Quaternion &l, const Quaternion &r) {
  ld a = l[0] * r[0] - l[1] * r[1] - l[2] * r[2] - l[3] * r[3];
  ld b = l[0] * r[1] + l[1] * r[0] + l[2] * r[3] - l[3] * r[2];
  ld c = l[0] * r[2] + l[2] * r[0] + l[3] * r[1] - l[1] * r[3];
  ld d = l[0] * r[3] + l[3] * r[0] + l[1] * r[2] - l[2] * r[1];
  return Quaternion({a, b, c, d});
}

Quaternion &operator*=(Quaternion &l, const Quaternion &r) { return l = l * r; }

Quaternion inv(const Quaternion &x) { return conj(x) / norm(x); }

Quaternion make_quaternion(const Point3D &axis, const ld theta) {
  const ld k = sin(theta / 2) / abs(axis);
  return Quaternion({cos(theta / 2), axis[0] * k, axis[1] * k, axis[2] * k});
}

Point3D rotate(Quaternion rot, const Point3D &x) {
  Quaternion a({0, x[0], x[1], x[2]});
  Quaternion b = rot * a * conj(rot);
  return Point3D({b[1], b[2], b[3]});
}

void GoogleCodeJam::exec() const {
  ld X;
  cin >> X;
  const ld max_theta = atan(sqrt(2.0L));
  const Point3D axis({1, 0, 1});
  ld lb = 0, ub = max_theta;
  REP(i,300) {
    ld mid = (lb + ub) / 2;
    const auto rot = make_quaternion(axis, mid);
    const Point3D vec({0, 1, 0});
    Point3D p1({1, 0, 0}); p1 = rotate(rot, p1);
    Point3D p2({0, 1, 0}); p2 = rotate(rot, p2);
    Point3D p3({0, 0, 1}); p3 = rotate(rot, p3);
    const ld area = abs(dot(p1, vec)) + abs(dot(p2, vec)) + abs(dot(p3, vec));
    if (area < X) lb = mid; else ub = mid;
  }
  const auto rot = make_quaternion(axis, lb);
  Point3D p1({0.5, 0, 0}); p1 = rotate(rot, p1);
  Point3D p2({0, 0.5, 0}); p2 = rotate(rot, p2);
  Point3D p3({0, 0, 0.5}); p3 = rotate(rot, p3);
  cout << p1[0] << " " << p1[1] << " " << p1[2] << endl;
  cout << p2[0] << " " << p2[1] << " " << p2[2] << endl;
  cout << p3[0] << " " << p3[1] << " " << p3[2] << endl;
}
