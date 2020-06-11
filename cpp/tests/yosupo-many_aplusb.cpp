#include "../include/others/fast_cin.cpp"
#include "../include/others/fast_cout.cpp"

int main() {
  int T;
  long long x, y;
  fcin >> T;
  while (T--) {
    fcin >> x >> y;
    fcout << x + y << fendl;
  }
  return 0;
}
