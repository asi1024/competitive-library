#include "../include/graph/bfs01.cpp"
#include "../include/graph/weighted_graph.hpp"

#define REP(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

int H, W, A;
string str[128];
int getId(int i, int j, int a, int b, int dir) {
  return i * W * (A + 1) * (A + 1) * 4 + j * (A + 1) * (A + 1) * 4 +
         a * (A + 1) * 4 + b * 4 + dir;
}

int main() {
  cin >> H >> W >> A;
  REP(i, H) cin >> str[i];
  int starty = -1, startx = -1, goaly = -1, goalx = -1;
  REP(i, H) REP(j, W) {
    if (str[i][j] == 'S')
      starty = i, startx = j;
    if (str[i][j] == 'G')
      goaly = i, goalx = j;
  }
  WeightedGraph<int> g(H * W * (A + 1) * (A + 1) * 4);
  REP(i, H - 1) REP(j, W) REP(a, A + 1) REP(b, A + 1) {
    if (str[i + 1][j] != '#')
      g.add(getId(i, j, a, b, 3), getId(i + 1, j, a, b, 3), 0);
    if (str[i + 1][j] == '.') {
      if (a > 0)
        g.add(getId(i, j, a, b, 3), getId(i + 1, j, a - 1, b, 0), 1);
      if (b > 0)
        g.add(getId(i, j, a, b, 3), getId(i + 1, j, a, b - 1, 2), 1);
    }
    if (str[i][j] == '.' || str[i][j] == 'G') {
      g.add(getId(i + 1, j, a, b, 1), getId(i, j, a, b, 1), 0);
      if (a > 0)
        g.add(getId(i + 1, j, a, b, 1), getId(i, j, a - 1, b, 2), 1);
      if (b > 0)
        g.add(getId(i + 1, j, a, b, 1), getId(i, j, a, b - 1, 0), 1);
    }
  }
  REP(i, H) REP(j, W - 1) REP(a, A + 1) REP(b, A + 1) {
    if (str[i][j + 1] != '#')
      g.add(getId(i, j, a, b, 0), getId(i, j + 1, a, b, 0), 0);
    if (str[i][j + 1] == '.') {
      if (a > 0)
        g.add(getId(i, j, a, b, 0), getId(i, j + 1, a - 1, b, 3), 1);
      if (b > 0)
        g.add(getId(i, j, a, b, 0), getId(i, j + 1, a, b - 1, 1), 1);
    }
    if (str[i][j] != '#')
      g.add(getId(i, j + 1, a, b, 2), getId(i, j, a, b, 2), 0);
    if (str[i][j] == '.') {
      if (a > 0)
        g.add(getId(i, j + 1, a, b, 2), getId(i, j, a - 1, b, 1), 1);
      if (b > 0)
        g.add(getId(i, j + 1, a, b, 2), getId(i, j, a, b - 1, 3), 1);
    }
  }
  vector<int> d = bfs01(g, getId(starty, startx, A, A, 3));
  int res = inf<int>();
  REP(a, A + 1)
  REP(b, A + 1) REP(dir, 4) res = min(res, d[getId(goaly, goalx, a, b, dir)]);
  cout << (res == inf<int>() ? -1 : res) << endl;
  return 0;
}
