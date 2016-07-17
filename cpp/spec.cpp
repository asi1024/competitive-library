#include "Structure/unionfind.cpp"
#include "Structure/segment_tree.cpp"
#include "Structure/fenwick_tree.cpp"
#include "Structure/starry_sky_tree.cpp"
#include "Structure/slide_min.cpp"
#include "Structure/skew_heap.cpp"

#include "Graph/Graph.hpp"
#include "Graph/dijkstra.cpp"
#include "Graph/spfa.cpp"
#include "Graph/bfs01.cpp"
#include "Graph/max_flow.cpp"
#include "Graph/min_cost_flow.cpp"
#include "Graph/bipartite_matching.cpp"
#include "Graph/lca.cpp"
#include "Graph/recession.cpp"

#include "Math/mod.cpp"
#include "Math/eratosthenes.cpp"
#include "Math/vector.cpp"
#include "Math/matrix.cpp"
#include "Math/fft.cpp"

#include "Geometry/Geometry.hpp"
#include "Geometry/intersect.cpp"
#include "Geometry/distance.cpp"
#include "Geometry/intersect_circle.cpp"
#include "Geometry/convex.cpp"

#include "String/rolling_hash.cpp"
#include "String/kmp.cpp"

#include "Others/cout.cpp"

#include "template.cpp"

void spec() {
  std::cout << "-- spec --" << std::endl;
// Math
  std::cout << "Math/mod-factorial" << std::endl;
  assert (comb<mod>(10, 4) == Mod(210));
  std::cout << "Math/eratosthenes" << std::endl;
  primes();
  std::cout << "OK!" << std::endl;
}

struct Spec {
  Spec() { spec(); }
};

Spec sp;
