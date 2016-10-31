#include "../util.hpp"

double test_isis_ll() {
  auto l1 = random_lines();
  auto l2 = random_lines();
  Timer timer;
  for (int i = 0; i < query_num; ++i)
    isis_ll(l1[i], l2[i]);
  return timer.stop() / query_num;
}

double test_isis_ls() {
  auto l1 = random_lines();
  auto s2 = random_segments();
  Timer timer;
  for (int i = 0; i < query_num; ++i)
    isis_ls(l1[i], s2[i]);
  return timer.stop() / query_num;
}

double test_isis_lp() {
  auto l1 = random_lines();
  auto p2 = random_points();
  Timer timer;
  for (int i = 0; i < query_num; ++i)
    isis_lp(l1[i], p2[i]);
  return timer.stop() / query_num;
}

double test_isis_ss() {
  auto s1 = random_segments();
  auto s2 = random_segments();
  Timer timer;
  for (int i = 0; i < query_num; ++i)
    isis_ss(s1[i], s2[i]);
  return timer.stop() / query_num;
}

double test_isis_sp() {
  auto s1 = random_segments();
  auto p2 = random_points();
  Timer timer;
  for (int i = 0; i < query_num; ++i)
    isis_sp(s1[i], p2[i]);
  return timer.stop() / query_num;
}

double test_proj() {
  auto l1 = random_lines();
  auto p2 = random_points();
  Timer timer;
  for (int i = 0; i < query_num; ++i)
    proj(l1[i], p2[i]);
  return timer.stop() / query_num;
}

double test_mirror() {
  auto l1 = random_lines();
  auto p2 = random_points();
  Timer timer;
  for (int i = 0; i < query_num; ++i)
    mirror(l1[i], p2[i]);
  return timer.stop() / query_num;
}

double test_is_ll() {
  auto l1 = random_lines();
  auto l2 = random_lines();
  Timer timer;
  for (int i = 0; i < query_num; ++i)
    is_ll(l1[i], l2[i]);
  return timer.stop() / query_num;
}
