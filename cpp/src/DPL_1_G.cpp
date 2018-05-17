#include "../include/structure/slide_min.cpp"

int main() {
  int n, W;
  scanf("%d%d", &n, &W);
  vector<int> dp(W + 1, 0);
  for (int i = 0; i < n; ++i) {
    vector<int> dp_next(W + 1, 0);
    int v, w, m;
    scanf("%d%d%d", &v, &w, &m);
    vector<SlideMin<int>> slide_min(w);
    for (int j = 0; j <= W; ++j) {
      SlideMin<int> &s = slide_min[j % w];
      s.push(-(dp[j] - j / w * v));
      if (s.size() > m + 1)
        s.pop();
      dp_next[j] = -s.minimum() + j / w * v;
    }
    dp.swap(dp_next);
  }
  printf("%d\n", dp[W]);
  return 0;
}
