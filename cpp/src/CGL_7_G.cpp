#include "../include/geometry/circle_intersect.cpp"
#include "../include/geometry/circle_tangent.cpp"
#include "../include/template/initialize.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;
using C = Circle<float11>;

int main() {
  P p1, p2;
  float11 r1, r2;
  cin >> p1 >> r1 >> p2 >> r2;
  C c1(p1, r1), c2(p2, r2);
  vector<L> ls = tangent_cc(c1, c2);
  vector<P> res;
  for (L l : ls) res.push_back(proj(l, c1.p));
  sort(begin(res), end(res));
  for (P p : res) cout << p << endl;
  return 0;
}
