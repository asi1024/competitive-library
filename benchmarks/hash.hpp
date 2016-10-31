#include "def.hpp"

using ull = unsigned long long;

ull my_hash(const int &n, mt19937 &mt) {
  return ull(n) * ull(mt());
}

ull my_hash(const long long &n, mt19937 &mt) {
  return ull(n) * ull(mt());
}

ull my_hash(const unsigned long long &n, mt19937 &mt) {
  return ull(n) * ull(mt());
}

ull my_hash(const long double &n, mt19937 &mt) {
  return ull(n - 0.123456789) * ull(mt());
}

template<typename T> ull my_hash(const complex<T> &n, mt19937 &mt) {
  return my_hash(real(n), mt) + my_hash(imag(n), mt);
}

template<typename U, typename T> ull my_hash(const pair<U, T> &n, mt19937 &mt) {
  return my_hash(n.first, mt) + my_hash(n.second, mt);
}

template<typename T> ull my_hash(const vector<T> &n, mt19937 &mt) {
  ull sum = 0;
  for (const T &i: n) sum += my_hash(i, mt);
  return sum;
}

template<typename T> ull my_hash(T n) { mt19937 mt(0); return my_hash(n, mt); }
