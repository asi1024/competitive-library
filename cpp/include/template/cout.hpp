#pragma once

#include <cstdio>
#include <string>

class fast_ostream {
  char ch[32];
  template<typename T>
  inline void put_integer(const T &var) {
    int n = var;
    if (n == 0) {
      putchar_unlocked('0');
      return;
    }
    else if (n < 0) {
      putchar_unlocked('-');
      n = -n;
    }
    int count = 0;
    while (n != 0) {
      ch[count++] = n % 10 + '0';
      n /= 10;
    }
    while (count--) {
      putchar_unlocked(ch[count]);
    }
  }
public:
  inline fast_ostream& operator<<(const int &var) {
    put_integer(var);
    return *this;
  }
  inline fast_ostream& operator<<(const long long &var) {
    put_integer(var);
    return *this;
  }
  inline fast_ostream& operator<<(const std::string &var) {
    for (char c: var) putchar_unlocked(c);
    return *this;
  }
};

fast_ostream fcout;

const std::string fendl = "\n";
