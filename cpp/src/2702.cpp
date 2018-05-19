#include "../include/graph/retrograde.cpp"

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int H, W, R, C;
  for (;;) {
    scanf("%d%d%d%d", &H, &W, &R, &C);
    if (H == 0 && W == 0 && R == 0 && C == 0) break;
    vector<vector<int>> horz(H + 1, vector<int>(W)),
      vert(H, vector<int>(W + 1));
    REP(i, H + 1) {
      if (i > 0) REP(j, W + 1) scanf("%d", &vert[i - 1][j]);
      REP(j, W) scanf("%d", &horz[i][j]);
    }
    Graph g(3 * H * W + 1);
    const int goal = 3 * H * W;
    const int start = ((R - 1) * W + (C - 1)) * 3;
    REP(i, H) add_edge(g, i * W * 3 + vert[i][0], goal);
    REP(i, H) add_edge(g, (i * W + W - 1) * 3 + vert[i][W], goal);
    REP(j, W) add_edge(g, j * 3 + horz[0][j], goal);
    REP(j, W) add_edge(g, ((H - 1) * W + j) * 3 + horz[H][j], goal);
    REP(i, H)
    REP(j, W) REP(k, 2) add_edge(g, (i * W + j) * 3 + 2, (i * W + j) * 3 + k);
    REP(i, H) REP(j, W - 1) {
      add_edge(g, (i * W + j) * 3 + vert[i][j + 1], (i * W + j + 1) * 3 + 2);
      add_edge(g, (i * W + j + 1) * 3 + vert[i][j + 1], (i * W + j) * 3 + 2);
    }
    REP(i, H - 1) REP(j, W) {
      add_edge(g, (i * W + j) * 3 + horz[i + 1][j], ((i + 1) * W + j) * 3 + 2);
      add_edge(g, ((i + 1) * W + j) * 3 + horz[i + 1][j], (i * W + j) * 3 + 2);
    }
    Game res = retrograde(g)[start];
    if (res == WIN)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
