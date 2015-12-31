#pragma once

#include "Graph.hpp"

template <typename Weight>
Weight min_cost_flow(Graph<Weight> &g, int s, int t, Flow f) {
  const int V = g.size();
  const Weight INF = 1000000000;
  // const Weight eps = 1e-8;
  vector<Weight> h(V, 0), dist(V, 0);
  vector<int> prevv(V), preve(V);
  Weight res = 0;
  typedef pair<Weight, int> P;
  while (f > 0) {
    priority_queue<P, vector<P>, greater<P>> que;
    fill(begin(dist), end(dist), INF);
    dist[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
      P p = que.top(); que.pop();
      int v = p.second;
      if (dist[v] < p.first) continue;
      for (int i = 0; i < (int)g[v].size(); ++i) {
        auto &e = g[v][i];
        if (e.cap <= 0) continue;
        if (dist[e.to] > dist[v] + e.cost + h[v] - h[e.to] /* + eps */) {
          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
          prevv[e.to] = v;
          preve[e.to] = i;
          que.push(P(dist[e.to], e.to));
        }
      }
    }
    if (dist[t] == INF) return -1;
    for (int v = 0; v < V; ++v) h[v] += dist[v];

    Flow d = f;
    for (int v = t; v != s; v = prevv[v])
      d = min(d, g[prevv[v]][preve[v]].cap);
    f -= d;
    res += d * h[t];
    for (int v = t; v != s; v = prevv[v]) {
      auto &e = g[prevv[v]][preve[v]];
      e.cap -= d;
      g[v][e.rev].cap += d;
    }
  }
  return res;
}

// Verified : AOJ 0290 (Microorganism Power Generation)
/*
int bm[16], bw[16];

int main() {
  int M, N;
  while (cin >> M >> N, M) {
    REP(i,M) cin >> bm[i];
    REP(i,N) cin >> bw[i];
    Graph<int> g(M + N + 2);
    const int src = M + N, sink = M + N + 1;
    REP(i,M) add_edge(g, src, i, 1, 0);
    REP(i,N) add_edge(g, i+M, sink, 1, 0);
    REP(i,M) REP(j,N) {
      int diff = abs(bm[i] - bw[j]);
      int c = diff * (diff - 30) * (diff - 30);
      add_edge(g, i, j+M, 1, -c);
    }
    cout << -min_cost_flow(g, src, sink, min(M, N)) << endl;
  }
  return 0;
}
*/
