#pragma once

#include "../template/includes.hpp"

class BipartiteMatching {
  static const int INF = 1000000000;
  const int n1, n;
  std::vector<std::vector<int>> g;
  std::vector<int> match, dist;
  bool bfs() {
    std::queue<int> que;
    std::fill(std::begin(dist), std::begin(dist) + n1, INF);
    for (int i = 0; i < n1; ++i) {
      if (match[i] == n) {
        dist[i] = 0;
        que.push(i);
      }
    }
    dist[n] = INF;
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      if (dist[u] < dist[n]) {
        for (int v : g[u]) {
          if (dist[match[v]] == INF) {
            dist[match[v]] = dist[u] + 1;
            que.push(match[v]);
          }
        }
      }
    }
    return (dist[n] != INF);
  }
  bool dfs(int u) {
    if (u != n) {
      for (int v : g[u]) {
        if (dist[match[v]] == dist[u] + 1 && dfs(match[v])) {
          match[v] = u;
          match[u] = v;
          return true;
        }
      }
      dist[u] = INF;
      return false;
    }
    return true;
  }

public:
  BipartiteMatching(int v1, int v2) :
    n1(v1), n(v1 + v2), g(n + 1), match(n + 1), dist(n + 1) {
    ;
  }
  void add(int u, int v) {
    g[u].push_back(v + n1);
    g[v + n1].push_back(u);
  }
  int maximum_matching() {
    int res = 0;
    std::fill(std::begin(match), std::begin(match) + n, n);
    while (bfs()) {
      for (int i = 0; i < n1; ++i) {
        if (match[i] == n && dfs(i)) ++res;
      }
    }
    return res;
  }
};
