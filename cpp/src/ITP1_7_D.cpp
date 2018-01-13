#include "../include/math/vector.cpp"

#define REP(i,n) for(int i=0;i<(n);++i)

int main() {
  int N, M, L;
  scanf("%d%d%d", &N ,&M, &L);
  Matrix<ll> A(N, M), B(M, L);
  REP(i,N) REP(j,M) cin >> A[i][j];
  REP(i,M) REP(j,L) cin >> B[i][j];
  auto res = A * B;
  REP(i,N) REP(j,L) cout << res[i][j] << " \n"[j == L - 1];
  return 0;
}
