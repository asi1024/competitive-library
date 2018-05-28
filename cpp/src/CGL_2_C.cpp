#include "../include/geometry/intersect.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;

int main() {
  cout << setprecision(12) << fixed;
  int q;
  cin >> q;
  while (q--) {
    P a, b, c, d;
    cin >> a >> b >> c >> d;
    L l1(a, b), l2(c, d);
    P res = is_ll(l1, l2);
    cout << res << endl;
  }
  return 0;
}
