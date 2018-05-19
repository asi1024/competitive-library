#pragma once

#include "../template/const_value.hpp"
#include "definition.hpp"

template <typename edge_t, typename cap_type = typename edge_t::capacity_type>
cap_type augment(graph_t<edge_t> &g, std::vector<int> &d,
                 std::vector<int> &iter, int v, int t, const cap_type &f) {
  if (v == t) {
    return f;
  }
  for (int &i = iter[v]; i < (int)g[v].size(); i++) {
    auto &e = g[v][i];
    if (e.cap > zero<cap_type>() && d[v] < d[e.to]) {
      cap_type ff = augment(g, d, iter, e.to, t, std::min(f, e.cap));
      if (ff > zero<cap_type>()) {
        e.cap -= ff;
        g[e.to][e.rev].cap += ff;
        return ff;
      }
    }
  }
  return zero<cap_type>();
}

template <typename edge_t, typename cap_type = typename edge_t::capacity_type>
cap_type max_flow(graph_t<edge_t> &g, int s, int t) {
  const int V = g.size();
  cap_type flow = zero<cap_type>();
  for (;;) {
    std::vector<int> d(V, -1);
    std::queue<int> que;
    d[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int v = que.front();
      que.pop();
      for (const auto &e : g[v]) {
        if (e.cap <= zero<cap_type>() || d[e.to] >= 0)
          continue;
        d[e.to] = d[v] + 1;
        que.push(e.to);
      }
    }
    if (d[t] < 0)
      return flow;
    std::vector<int> iter(V, 0);
    cap_type f;
    while ((f = augment(g, d, iter, s, t, inf<cap_type>())) > 0)
      flow += f;
  }
}
