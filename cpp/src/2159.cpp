#include "../include/geometry/convex.cpp"

using namespace std;

using P = Point<float11>;
using L = Line<float11>;
using G = Polygon<float11>;

int main() {
  int n;
  cin >> n;
  vector<P> poly, sorted;
  for (int i = 0; i < n; ++i) {
    P p;
    cin >> p;
    poly.push_back(p);
    sorted.push_back(p);
  }
  G ch = convex_hull(poly);
  const int m = ch.size();
  G g;
  for (int i = 0; i < m; ++i) {
    g.push_back(ch[i]);
    g.push_back(average(ch[i], ch[i + 1]));
  }
  sort(begin(sorted), end(sorted));
  bool res = false;
  for (int i = 0; i < m; ++i) {
    bool ok = true;
    L l(g[i], g[i + m]);
    if (abs(l.a - l.b) <= 0) continue;
    int cnt = 0;
    for (int j = 0; j < n; ++j) {
      const P p = poly[j];
      const P x = average(proj(l, p), p, 2, -1);
      if (!binary_search(begin(sorted), end(sorted), x)) ok = false;
      if (x == p) ++cnt;
    }
    if (ok && cnt <= 2) res = true;
  }
  puts(res ? "Yes" : "No");
}
