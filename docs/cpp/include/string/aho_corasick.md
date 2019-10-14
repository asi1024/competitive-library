## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/string/aho_corasick.cpp)

{% highlight cpp %}
#include "../template/includes.hpp"

template <typename State> struct AhoCorasick {
  using string_t = typename State::string_t;
  using char_t = typename State::char_t;
  std::vector<State> pma;
  std::vector<int> lens;

  AhoCorasick(const std::vector<string_t> &str) : pma(0), lens(0) {
    pma.push_back(State());
    for (const string_t &s : str) {
      int t = 0;
      for (char_t c : s) {
        if (!pma[t].is_set(c)) {
          pma[t][c] = pma.size();
          pma.push_back(State());
        }
        t = pma[t][c];
      }
      pma[t].accept.push_back(lens.size());
      lens.push_back(s.size());
    }
    std::queue<int> que;
    for (char_t c = State::min_char; c <= State::max_char; c++) {
      if (pma[0].is_set(c)) {
        pma[pma[0][c]].fail = 0;
        que.push(pma[0][c]);
      }
      else {
        pma[0][c] = 0;
      }
    }
    while (!que.empty()) {
      int t = que.front();
      que.pop();
      for (char_t c = State::min_char; c <= State::max_char; c++) {
        if (pma[t].is_set(c)) {
          que.push(pma[t][c]);
          int r = pma[t].fail;
          while (!pma[r].is_set(c)) r = pma[r].fail;
          pma[pma[t][c]].fail = pma[r][c];
          for (int i : pma[pma[r][c]].accept) {
            pma[pma[t][c]].accept.push_back(i);
          }
        }
      }
    }
  }
  int next(int index, char_t c) {
    return pma[index].is_set(c) ? pma[index][c]
                                : pma[index][c] = next(pma[index].fail, c);
  }
  std::vector<int> query(string_t &t) {
    int index = 0;
    std::vector<int> ret(lens.size(), -1);
    for (int i = 0; i < int(t.size()); ++i) {
      char_t c = t[i];
      index = next(index, c);
      for (int j : pma[index].accept) {
        if (ret[j] != -1) continue;
        ret[j] = i - lens[j] + 1;
      }
    }
    return ret;
  }
};

struct State {
  using string_t = std::string;
  using char_t = char;
  static const char_t min_char = 'a';
  static const char_t max_char = 'z';
  std::array<int, max_char - min_char + 1> edge;
  int fail;
  std::vector<int> accept;
  State() : fail(0), accept(0) { std::fill(begin(edge), end(edge), -1); }
  int &operator[](char_t c) { return edge[c - 'a']; }
  const int &operator[](char_t c) const { return edge[c - 'a']; }
  bool is_set(char_t c) { return edge[c - 'a'] >= 0; }
};
{% endhighlight %}

### Includes

- [includes.hpp](../template/includes)

[Back](../..)
