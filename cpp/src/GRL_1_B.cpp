#include <cstdio>
#include <tuple>

#include "../include/graph/spfa.cpp"
#include "../include/graph/weighted_graph.hpp"

using namespace std;

int main() {
  int V, E, r, s, t, d;
  scanf("%d%d%d", &V, &E, &r);
  WeightedGraph<int> g(V);
  while (E--) {
    scanf("%d%d%d", &s, &t, &d);
    g.add(s, t, d);
  }
  vector<int> res = spfa(g, r);
  if (!res.empty()) {
    for (int i = 0; i < V; ++i) {
      if (res[i] == inf<int>) puts("INF");
      else printf("%d\n", res[i]);
    }
  }
  else {
    puts("NEGATIVE CYCLE");
  }
  return 0;
}
