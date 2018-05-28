#include "../include/geometry/convex.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;
using G = Polygon<float11>;

float11 f(P x) { return x.x() + x.y() * 1.2358132134; }

int main() {
  int n;
  cin >> n;
  vector<P> poly;
  vector<float11> vec;
  for (int i = 0; i < n; ++i) {
    P p;
    cin >> p;
    poly.push_back(p);
    vec.push_back(f(p));
  }
  G ch = convex_hull(poly);
  const int m = ch.size();
  G g;
  for (int i = 0; i < m; ++i) {
    g.push_back(ch[i]);
    g.push_back(average(ch[i], ch[i + 1]));
  }
  sort(begin(vec), end(vec));
  bool res = false;
  for (int i = 0; i < m; ++i) {
    bool ok = true;
    L l(g[i], g[i + m]);
    if (abs(l.a - l.b) <= 0) continue;
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      const P p = poly[j];
      const float11 x = f(average(proj(l, p), p, 2, -1));
      const float11 y = *lower_bound(begin(vec), end(vec), x);
      if (x - y != 0) ok = false;
      if (x - f(p) == 0) ++cnt;
    }
    if (ok && cnt <= 2) res = true;
  }
  puts(res ? "Yes" : "No");
}
