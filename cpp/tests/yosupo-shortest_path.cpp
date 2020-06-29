#include "../include/graph/dijkstra.cpp"
#include "../include/graph/weighted_graph.cpp"
#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"

using Graph = WeightedGraph<long long>;

int main() {
  int n, m, s, t;
  fcin >> n >> m >> s >> t;
  Graph rg(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    long long c;
    fcin >> a >> b >> c;
    add_edge(rg, b, a, c);
  }
  std::vector<int> prev;
  auto d = dijkstra(rg, t, prev);

  if (d[s] == inf<long long>()) {
    fcout << -1 << fendl;
    return 0;
  }

  std::vector<int> trace;
  trace.reserve(m);
  trace.push_back(s);
  while (trace.back() != t) {
    int v = trace.back();
    trace.push_back(prev[v]);
  }
  int size = trace.size() - 1;
  fcout << d[s] << " " << size << fendl;
  for (int i = 0; i < size; ++i) {
    fcout << trace[i] << " " << trace[i + 1] << fendl;
  }
  return 0;
}
