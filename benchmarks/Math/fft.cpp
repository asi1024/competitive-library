#include "../util.hpp"

double test_fft() {
  vector<ll> ary;
  for (int i: random_array()) {
    ary.push_back(i % 10);
  }
  Timer timer;
  convolution(ary, ary);
  return timer.stop() / query_num;
}
