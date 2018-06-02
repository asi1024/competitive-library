#include "template.cpp"

class GoogleCodeJam {
public:
  string case_prefix;
  void exec() const;
  GoogleCodeJam() {
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; i++) {
      case_prefix = "Case #" + std::to_string(i) + ":";
      exec();
    }
  }
};
