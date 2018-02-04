#include "../include/graph/retrograde_weighted.cpp"

#define REP(i,n) for(int i=0;i<(int)(n);i++)

bool edge[64][64];
bool dp[128][64][64];

int main() {
  int n, m, a, b, c;
  scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
  REP(i,m) {
    int u, v;
    scanf("%d%d", &u, &v);
    edge[u-1][v-1] = true;
  }
  REP(i,n) dp[0][i][i] = true;
  REP(i,101) REP(j,n) REP(k,n) REP(l,n) {
    if (dp[i][j][k] && edge[k][l]) dp[i+1][j][l] = true;
  }
  Graph g(4 * n + 1);
  const int start = 4 * n;
  add_edge(g, start, 0, 0);
  REP(i,n-1) REP(j,3) add_edge(g, 4 * i, 4 * i + j + 1, 0);
  REP(i,n) REP(j,n) {
    if (dp[a][i][j]) add_edge(g, 4 * i + 1, 4 * j, 1);
    if (dp[b][i][j]) add_edge(g, 4 * i + 2, 4 * j, 1);
    if (dp[c][i][j]) add_edge(g, 4 * i + 3, 4 * j, 1);
  }
  auto res = retrograde(g)[start];
  if (res.win == WIN) cout << res.cost << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}
