#pragma once

#include "definition.cpp"

template <typename edge_t>
void traversal_dfs(const graph_t<edge_t> &g, int v, std::vector<bool> &visited,
                   std::vector<int> &pre, std::vector<int> &post, int &cnt) {
  visited[v] = true;
  pre[v] = cnt++;
  for (const edge_t &e : g[v]) {
    if (!visited[e.to]) traversal_dfs(g, e.to, visited, pre, post, cnt);
  }
  post[v] = cnt++;
}

template <typename edge_t>
std::pair<std::vector<int>, std::vector<int>>
traversal(const graph_t<edge_t> &g, int s) {
  int n = g.size();
  std::vector<bool> visited(n, false);
  std::vector<int> pre_order(n, -1), post_order(n, -1);
  int cnt = 0;
  traversal_dfs(g, s, visited, pre_order, post_order, cnt);
  assert(cnt == n * 2);
  return make_pair(pre_order, post_order);
}
