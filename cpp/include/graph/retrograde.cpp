#include "definition.hpp"
#include "game.hpp"

template <typename edge_t>
std::vector<Game> retrograde(const graph_t<edge_t> &g) {
  const int n = g.size();
  std::vector<std::vector<int>> rg(n);
  for (int i = 0; i < n; ++i) {
    for (const auto &e : g[i]) rg[e.to].push_back(i);
  }
  std::vector<int> cnt(n);
  for (int i = 0; i < n; ++i) cnt[i] = g[i].size();
  std::queue<int> que;
  std::vector<Game> res(n, DRAW);
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 0) {
      res[i] = LOSE;
      que.emplace(i);
    }
  }
  while (!que.empty()) {
    int v = que.front();
    que.pop();
    if (res[v] == WIN) {
      for (int w : rg[v]) {
        if (res[w] == WIN) continue;
        cnt[w]--;
        if (cnt[w] == 0) {
          res[w] = LOSE;
          que.emplace(w);
        }
      }
    }
    else {
      for (int w : rg[v]) {
        if (res[w] != WIN) {
          res[w] = WIN;
          que.emplace(w);
        }
      }
    }
  }
  return res;
}
