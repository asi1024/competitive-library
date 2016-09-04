#include "STL/bitset.cpp"
#include "STL/priority_queue.cpp"
#include "STL/set.cpp"
#include "STL/sort.cpp"

#include "Structure/fenwick_tree.cpp"
#include "Structure/rars.cpp"
#include "Structure/segment_tree.cpp"
#include "Structure/skew_heap.cpp"
#include "Structure/slide_min.cpp"
#include "Structure/starry_sky_tree.cpp"
#include "Structure/unionfind.cpp"

#include "Graph/bfs01.cpp"
#include "Graph/dijkstra.cpp"
#include "Graph/lca.cpp"
#include "Graph/max_flow.cpp"
#include "Graph/min_cost_flow.cpp"
#include "Graph/spfa.cpp"

int main() {
  cout << setprecision(3) << fixed;

  cout << endl << "=== STL ===" << endl;
  check(test_sort, "STL Sort");
  check(test_priority_queue, "STL PQue");
  check(test_set, "STL Set");
  check(test_bitset, "STL Bitset");

  cout << endl << "=== Structure ===" << endl;
  check(test_unionfind, "UnionFind");
  check(test_segment_tree, "SegmentTree");
  check(test_fenwick_tree, "FenwickTree");
  check(test_rars, "RARS");
  check(test_starry_sky_tree, "StarrySkyTree");
  check(test_skew_heap, "SkewHeap");
  check(test_slide_min, "SlideMin");

  cout << endl << "=== Graph ===" << endl;
  check(test_dijkstra, "Dijkstra");
  check(test_spfa, "spfa");
  check(test_bfs01, "01-BFS");
  check(test_max_flow, "Dinic");
  check(test_min_cost_flow, "Primal Dual");
  check(test_lca, "LCA");
  return 0;
}
