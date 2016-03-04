#include "Structure/unionfind.cpp"
#include "Structure/segment_tree.cpp"
#include "Structure/fenwick_tree.cpp"
#include "Structure/starry_sky_tree.cpp"

#include "Graph/Graph.hpp"
#include "Graph/dijkstra.cpp"
#include "Graph/spfa.cpp"
#include "Graph/bfs01.cpp"
#include "Graph/max_flow.cpp"
#include "Graph/min_cost_flow.cpp"
#include "Graph/bipartite_matching.cpp"

#include "Math/mod.cpp"
#include "Math/eratosthenes.cpp"

#include "Geometry/Geometry.hpp"
#include "Geometry/intersect.cpp"
#include "Geometry/distance.cpp"
#include "Geometry/intersect_circle.cpp"

#include "template.cpp"

void spec() {
  std::cout << "-- spec --" << std::endl;
// Math
  std::cout << "Math/mod-factorial" << std::endl;
  fact_init();
  std::cout << "Math/eratosthenes" << std::endl;
  primes();
  std::cout << "OK!" << std::endl;
}

struct Spec {
  Spec() { spec(); }
};

Spec sp;
