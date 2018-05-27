#include "../include/geometry/circle_intersect.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;
using C = Circle<float11>;

int main() {
  ld cx, cy, r;
  cin >> cx >> cy >> r;
  C c(Point(cx, cy), r);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    P la, lb;
    cin >> la >> lb;
    L l = Line(la, lb);
    vector<P> res = is_cl(c, l);
    P pa = res[0], pb = (res.size() == 2 ? res[1] : res[0]);
    if (real(pa) > real(pb) + eps ||
        (real(pa) > real(pb) - eps && imag(pa) > imag(pb)))
      swap(pa, pb);
    cout << pa << " " << pb << endl;
  }
}
