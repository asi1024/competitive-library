#include "../include/geometry/polygon.cpp"

using namespace std;

using P = Point<float11>;
using G = Polygon<float11>;

int main() {
  cout << setprecision(12) << fixed;
  int n;
  cin >> n;
  G poly;
  for (int i = 0; i < n; ++i) {
    P p;
    cin >> p;
    poly.push_back(p);
  }
  cout << area(poly) << endl;
}
