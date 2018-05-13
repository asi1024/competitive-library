#pragma once

#include <vector>
#include <queue>
#include <utility>

#include "../template/const_value.hpp"
#include "definition.hpp"

/// @param g: 重み付きグラフ
/// @param s: 始点の頂点番号
/// @typereq edge_t
/// @return 始点から各頂点までの距離が入った型 cost_type の列
/// @complexity $O(EV)$
/// @brief
/// 重み付きグラフの単一始点全点間最短距離を求める．
template <typename edge_t, typename cost_type = typename edge_t::cost_type>
std::pair<bool,std::vector<cost_type>> spfa(const graph_t<edge_t> &g, int s) {
  const int n = g.size();
  std::vector<cost_type> d(n, inf<cost_type>); d[s] = zero<cost_type>;
  std::vector<int> updated(n, 0);
  std::vector<bool> inque(n, false);
  std::queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int from = que.front();
    que.pop();
    inque[from] = false;
    ++updated[from];
    if (updated[from] == n + 1) return {false, d}; // negative cycle
    for (const auto &e: g[from]) {
      cost_type cost = d[from] + e.cost;
      if (cost < d[e.to]) {
        d[e.to] = cost;
        if (!inque[e.to]) {
          que.push(e.to);
          inque[e.to] = true;
        }
      }
    }
  }
  return {true, d};
}
