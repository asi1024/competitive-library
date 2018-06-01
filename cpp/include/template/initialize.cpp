#include "includes.hpp"

struct yes_no : std::numpunct<char> {
  string_type do_truename() const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

struct Initialize {
  Initialize() {
    std::locale loc(std::locale(), new yes_no);
    std::cout << std::boolalpha << std::setprecision(11) << std::fixed;
    std::cout.imbue(loc);
  }
};

const Initialize init;
