#pragma once

#include "../util.hpp"

/// @param g: 負辺のない重み付きグラフ
/// @param s: 始点の頂点番号
/// @param zero: 型 Cost のゼロ値
/// @return 始点から各頂点までの距離が入った型 Cost の列
/// @note 入力グラフに不辺があってはならない
/// @complexity $O(E \\log V)$
/// @brief
/// 負辺のない重み付きグラフの単一始点全点間最短距離を求める．
template <typename Edge, typename Cost = typename Edge::Cost>
vector<Cost> dijkstra(const vector<vector<Edge>> &g, int s, Cost zero = 0) {
  vector<Cost> d(g.size(), inf<Cost>);
  d[s] = zero;
  using P = pair<Cost,int>;
  priority_queue<P, vector<P>, greater<P>> que;
  que.push(P(zero, s));
  while (!que.empty()) {
    Cost dist = que.top().first;
    int v = que.top().second;
    que.pop();
    if (d[v] < dist) continue;
    for (const auto &e: g[v]) {
      if (d[e.to] <= d[v] + e.cost) continue;
      d[e.to] = d[v] + e.cost;
      que.push(P(d[e.to], e.to));
    }
  }
  return d;
}

struct Edge {
  using Cost = int;
  int to;
  Cost cost;
  Edge(int t, Cost c) : to(t), cost(c) {}
};

using Graph = vector<vector<Edge>>;

void add_edge(Graph &g, int from, int to, Edge::Cost cost) {
  g[from].emplace_back(to, cost);
}
