#include "../util.hpp"

double test_bitset() {
  bitset<array_len> bit1, bit2;
  for (int i = 0; i < array_len; ++i) {
    bit1[i] = mt() % 2;
    bit2[i] = mt() % 2;
  }
  Timer timer;
  bit1 &= bit2;
  return timer.stop();
}
