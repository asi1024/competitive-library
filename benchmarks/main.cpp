#include "STL/priority_queue.cpp"
#include "STL/set.cpp"
#include "STL/sort.cpp"

// #include "Structure/fenwick_tree.cpp"
// #include "Structure/rars.cpp"
// #include "Structure/segment_tree.cpp"
// #include "Structure/skew_heap.cpp"
// #include "Structure/slide_min.cpp"
// #include "Structure/starry_sky_tree.cpp"
// #include "Structure/unionfind.cpp"

// #include "Graph/bfs01.cpp"
// #include "Graph/dijkstra.cpp"
// #include "Graph/lca.cpp"
// #include "Graph/max_flow.cpp"
// #include "Graph/min_cost_flow.cpp"
// #include "Graph/spfa.cpp"

// #include "Math/fft.cpp"

// #include "Geometry/intersect.cpp"
// #include "Geometry/intersect_circle.cpp"

int main() {
  cout << setprecision(3) << fixed;

  auto array_testsuite = random_array();

  cout << endl << "=== STL ===" << endl;
  array_testsuite.run("Sort", test_sort, 10377643567579487844ULL);
  array_testsuite.run("PQue", test_pque, 15317107113471489615ULL);
  array_testsuite.run("Set",  test_set,   9895682793213700656ULL);

  cout << endl << "=== Structure ===" << endl;
  // check(test_unionfind, "UnionFind");
  // check(test_segment_tree, "SegmentTree");
  // check(test_fenwick_tree, "FenwickTree");
  // check(test_rars, "RARS");
  // check(test_starry_sky_tree, "StarrySkyTree");
  // check(test_skew_heap, "SkewHeap");
  // check(test_slide_min, "SlideMin");

  cout << endl << "=== Graph ===" << endl;
  // check(test_dijkstra, "Dijkstra");
  // check(test_spfa, "spfa");
  // check(test_bfs01, "01-BFS");
  // check(test_max_flow, "Dinic");
  // check(test_min_cost_flow, "Primal Dual");
  // check(test_lca, "LCA");

  cout << endl << "=== Math ===" << endl;
  // check(test_fft, "FFT");

  cout << endl << "=== Geometry ===" << endl;
  // check(test_isis_ll, "isis_ll");
  // check(test_isis_ls, "isis_ls");
  // check(test_isis_lp, "isis_lp");
  // check(test_isis_ss, "isis_ss");
  // check(test_isis_sp, "isis_sp");
  // check(test_proj, "proj");
  // check(test_mirror, "mirror");
  // check(test_is_ll, "is_ll");
  // check(test_is_cc, "is_cc");
  // check(test_is_cl, "is_cl");
  // check(test_is_cs, "is_cs");
  return 0;
}
