#include "include/template/template.cpp"
{% if mod %} #include "include/types/mod.cpp" {% endif %}

{% if mod %}
const int mod = {{ mod }};
using Mod = Modulo<mod>;
{% endif %}

{% if yes_str and no_str %}
struct yes_no : std::numpunct<char> {
  string_type do_truename() const { return "{{ yes_str }}"; }
  string_type do_falsename() const { return "{{ no_str }}"; }
};

struct Initialize {
  Initialize() {
    std::locale loc(std::locale(), new yes_no);
    std::cout << std::boolalpha << std::setprecision(11) << std::fixed;
    std::cout.imbue(loc);
  }
};

const Initialize initialize;
{% endif %}

{% if yes_str %} const string yes = "{{ yes_str }}"; {% endif %}
{% if no_str %} const string no = "{{ no_str }}"; {% endif %}

template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}

{% if input_part and actual_arguments %}
void solve({{formal_arguments}}) {
  // FILL IN HERE.
}

int main() {
  {{input_part}}
  solve({{actual_arguments}});
  return 0;
}
{% else %}
int main() {
  // FILL IN HERE.
  return 0;
}
{% endif %}
