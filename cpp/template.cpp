#include <bits/stdc++.h>

using namespace std;

class rep {
  struct repi {
    size_t it;
    repi() : it(0) { }
    repi(size_t n) : it(n) {}
    bool operator==(const repi &rhs) const { return it == rhs.it; }
    bool operator!=(const repi &rhs) const { return it != rhs.it; }
    size_t& operator*() { return it; }
    repi& operator++() { ++it; return *this; }
  };
  size_t i;
public:
  rep(size_t n) : i(n) { }
  repi begin() const { return 0; }
  repi end() const { return i; }
};

using ll = long long;
using ld = long double;

const int INF = 1e9;

int main() {

  return 0;
}
