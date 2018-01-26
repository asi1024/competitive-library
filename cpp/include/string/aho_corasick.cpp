#pragma once

#include "../util.hpp"

template<typename State>
struct AhoCorasick {
  using string_t = State::string_t;
  using char_t = State::char_t;
  vector<State> pma;
  vector<int> lens;

  AhoCorasick(const vector<string_t> &str) : pma(0), lens(0) {
    pma.push_back(State());
    for (const string_t &s: str) {
      int t = 0;
      for (char_t c: s) {
        if (pma[t].next[c] == -1) {
          int m = pma.size();
          pma[t].next[(int)c] = m;
          pma.push_back(State(m));
        }
        t = pma[t].next[c];
      }
      pma[t].accept.push_back(lens.size());
      lens.push_back(str[i].size());
    }

    queue<int> que;
    for (int c = 1; c < SIZE; c++) {
      if (pma[0].next[c] != -1) {
        pma[pma[0].next[c]].next[0] = 0;
        que.push(pma[0].next[c]);
      }
      else {
        pma[0].next[c] = 0;
      }
    }
    while (!que.empty()) {
      int t = que.front();
      que.pop();
      for (int c = 1; c < SIZE; c++) {
        if (pma[t].next[c] != -1) {
          que.push(pma[t].next[c]);
          int r = pma[t].next[0];
          while (pma[r].next[c] == -1) r = pma[r].next[0];
          pma[pma[t].next[c]].next[0] = pma[r].next[c];
          for (int i : pma[pma[r].next[c]].accept)
            pma[pma[t].next[c]].accept.push_back(i);
        }
      }
    }
  }

  int sub(int index, int c) {
    return pma[index].next[c] != -1 ?
      pma[index].next[c] :
      pma[index].next[c] = sub(pma[index].next[0], c);
  }

  vector<int> query(string &t) {
    int index = 0;
    vector<int> ret(lens.size(), -1);
    REP(i,t.size()) {
      int c = t[i];
      index = sub(index, c);
      for (int j : pma[index].accept) {
        if (ret[j] != -1) continue;
        ret[j] = i - lens[j] + 1;
      }
    }
    return ret;
  }
};

class State {
  using string_t = string;
  using char_t = char;
  using reference = int&;
  using const_reference = const int&;
  array<int, 26> edge;
  int fail;
  vector<int> accept;
public:
  State() : fail(0), accept(0) { fill(begin(edge), end(edge), -1); }
  reference operator[] (char_t c) { return edge[c - 'a']; }
  const_reference operator[] (char_t c) const { return edge[c - 'a']; }
  reference fail(int x) { return fail; }
  const_reference fail(int x) const { return fail; }
  void push(int x) { accept.push_back(x); }
  bool find(int x) const {
    return find(begin(accept), end(accept), x) != end(accept);
  }
};
