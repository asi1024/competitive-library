#include "includes.hpp"
#include "macros.hpp"
#include "range.hpp"
#include "const_value.hpp"
#include "misc.hpp"

using namespace std;

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha;
  cout.imbue(loc);

  return 0;
}
