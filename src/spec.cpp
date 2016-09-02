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

mt19937 mt(0);
uniform_real_distribution<> rnd(-100, 100);

Point rnd_point() { return Point(rnd(mt), rnd(mt)); }
Segment rnd_segment() { return Segment(rnd_point(), rnd_point()); }
Line rnd_line() { return Line(rnd_segment()); }
Circle rnd_circle() { return Circle(rnd_point(), rnd(mt)); }
Polygon rnd_polygon() {
  Polygon poly;
  for (int i = 0; i < 30; ++i) poly.push_back(rnd_point());
  return convex_hull(unique(poly));
}

template<class A, class B>
void check(A a, B b) {
  vector<__typeof(a(b()))> res;
  for (int i = 0; i < 20; ++i) res.push_back(a(b()));
  std::cout << res << endl;
}

template<class A, class B, class C>
void check(A (*a)(B, C), B (*b)(), C (*c)()) {
  vector<A> res;
  for (int i = 0; i < 20; ++i) res.push_back(a(b(), c()));
  std::cout << res << endl;
}

template<class A, class B, class C>
void check(A a, B b, C c) {
  vector<__typeof(a(b(), c()))> res;
  for (int i = 0; i < 20; ++i) res.push_back(a(b(), c()));
  std::cout << res << endl;
}

void spec() {
  std::cout << "-- spec --" << std::endl;
// Math
  std::cout << "Math/mod-factorial" << std::endl;
  assert (comb<mod>(10, 4) == Mod(210));

  std::cout << "Math/eratosthenes" << std::endl;
  primes();

  std::cout << "Math/convolution" << std::endl;
  std::vector<long long> a(100), b(300);
  iota(begin(a), end(a), 0);
  iota(begin(b), end(b), 0);
  convolution(a, b);

  std::cout << "Geometry/intersect" << std::endl;
  check(isis_ll, rnd_line,    rnd_line);
  check(isis_ls, rnd_line,    rnd_segment);
  check(isis_lp, rnd_line,    rnd_point);
  check(isis_ss, rnd_segment, rnd_segment);
  check(isis_sp, rnd_segment, rnd_point);
  check<Point, Line, Point>(proj, rnd_line, rnd_point);
  check(mirror,  rnd_line,    rnd_point);
  check(is_ll,   rnd_line,    rnd_line);

  std::cout << "Geometry/intersect" << std::endl;
  check(dist_lp, rnd_line,    rnd_point);
  check(dist_ll, rnd_line,    rnd_line);
  check(dist_ls, rnd_line,    rnd_segment);
  check(dist_sp, rnd_segment, rnd_point);
  check(dist_ss, rnd_segment, rnd_segment);
  std::cout << "OK!" << std::endl;

  std::cout << "Geometry/convex" << std::endl;
  check(area,          rnd_polygon);
  check(is_polygon,    rnd_polygon, rnd_segment);
  check(is_in_polygon, rnd_polygon, rnd_point);
  check(max_distance,  rnd_polygon);

  std::cout << "Geometry/intersect_circle" << std::endl;
  check(is_cc, rnd_circle, rnd_circle);
  check(is_cl, rnd_circle, rnd_line);
  check(is_cs, rnd_circle, rnd_segment);
}

struct Spec {
  Spec() { spec(); }
};

Spec sp;
