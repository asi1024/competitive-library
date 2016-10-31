#include "../gen_array.hpp"

vector<int> test_sort(vector<int> ary) {
  sort(begin(ary), end(ary));
  return ary;
}
