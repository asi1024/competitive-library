#pragma once

#include "../template/const_value.hpp"
#include "definition.hpp"

/// @param g: 負辺のない重み付きグラフ
/// @param s: 始点の頂点番号
/// @typereq edge_t
/// @return 始点から各頂点までの距離が入った型 cost_type の列
/// @note 入力グラフの辺のコストは全て 0 か 1 である
/// @complexity $O(E)$
/// @brief
/// コストが 0 か 1 のみの重み付きグラフの単一始点全点間最短距離を求める．
template <typename edge_t, typename cost_type = typename edge_t::cost_type>
std::vector<
  typename std::enable_if<std::is_integral<cost_type>::value, cost_type>::type>
bfs01(const graph_t<edge_t> &g, int s) {
  std::vector<cost_type> d(g.size(), inf<cost_type>());
  d[s] = cost_type(0);
  std::deque<std::pair<cost_type, int>> que;
  que.emplace_back(zero<cost_type>(), s);
  while (!que.empty()) {
    auto top = que.front();
    que.pop_front();
    cost_type dist = top.first;
    int v = top.second;
    if (d[v] < dist) continue;
    for (const auto &e : g[v]) {
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        if (e.cost == cost_type(1)) {
          que.emplace_back(d[e.to], e.to);
        }
        else if (e.cost == cost_type(0)) {
          que.emplace_front(d[e.to], e.to);
        }
        else {
          assert(false);
        }
      }
    }
  }
  return d;
}
