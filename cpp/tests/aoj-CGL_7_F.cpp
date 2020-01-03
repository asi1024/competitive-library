#include "../include/geometry/circle_intersect.cpp"
#include "../include/geometry/circle_tangent.cpp"
#include "../include/template/initialize.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;
using C = Circle<float11>;

int main() {
  P p, cp;
  float11 r;
  cin >> p >> cp >> r;
  const C c(cp, r);
  vector<L> ls = tangent_cp(c, p);
  vector<P> res;
  for (L l : ls) res.push_back(proj(l, c.p));
  P pa = res[0], pb = res[1];
  if (pa > pb) swap(pa, pb);
  cout << pa << endl << pb << endl;
  return 0;
}
