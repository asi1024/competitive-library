#include "../include/geometry/circle_intersect.cpp"
#include "../include/template/initialize.cpp"

using namespace std;

using P = Point<float11>;
using C = Circle<float11>;

int main() {
  P p1, p2;
  float11 r1, r2;
  cin >> p1 >> r1 >> p2 >> r2;
  C c1(p1, r1), c2(p2, r2);
  vector<P> res = is_cc(c1, c2);
  P pa = res[0], pb = (res.size() == 2 ? res[1] : res[0]);
  if (pa > pb) swap(pa, pb);
  cout << pa << " " << pb << endl;
  return 0;
}
