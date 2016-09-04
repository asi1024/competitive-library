#include "../util.hpp"

double test_is_cc() {
  auto c1 = random_circles();
  auto c2 = random_circles();
  Point sum;
  Timer timer;
  for (int i = 0; i < query_num; ++i)
    sum += is_cc(c1[i], c2[i]).empty();
  return timer.stop() / query_num + zero(sum);
}

double test_is_cl() {
  auto c1 = random_circles();
  auto l2 = random_lines();
  Point sum;
  Timer timer;
  for (int i = 0; i < query_num; ++i)
    sum += is_cl(c1[i], l2[i]).empty();
  return timer.stop() / query_num + zero(sum);
}

double test_is_cs() {
  auto c1 = random_circles();
  auto s2 = random_segments();
  Point sum;
  Timer timer;
  for (int i = 0; i < query_num; ++i)
    sum += is_cs(c1[i], s2[i]).empty();
  return timer.stop() / query_num + zero(sum);
}
