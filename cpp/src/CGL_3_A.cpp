#include "../include/geometry/polygon.cpp"
#include "../include/template/initialize.cpp"

using namespace std;

using P = Point<float11>;
using G = Polygon<float11>;

int main() {
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
