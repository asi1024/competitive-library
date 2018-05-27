#include "../include/geometry/intersect.cpp"

#include <iomanip>

using namespace std;

using P = Point<float11>;
using L = Line<float11>;

int main() {
  cout << setprecision(11) << fixed;
  P a, b, p;
  cin >> a >> b;
  L l(a, b);
  int q;
  cin >> q;
  while (q--) {
    cin >> p;
    P res = proj(l, p);
    cout << res.x() << " " << res.y() << endl;
  }
}
