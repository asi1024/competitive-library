template<typename State, typename Input = string>
struct AhoCorasick {
  static const int SIZE = 128;

  vector<State> pma;
  vector<int> lens;

  AhoCorasick(const vector<string> &str) {
    pma.clear();
    pma.push_back(State(0));
    lens.clear();

    REP(i,str.size()) {
      int t = 0;
      for (char c : str[i]) {
        if (pma[t].next[(int)c] == -1) {
          int m = pma.size();
          pma[t].next[(int)c] = m;
          pma.push_back(State(m));
        }
        t = pma[t].next[(int)c];
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
  using reference = int&;
  using const_reference = const int&;
  array<int, 26> edge;
  vector<int> accept;
public:
  State() { fill(begin(edge), end(edge), -1); }
  reference operator[] (char c) { return edge[c - 'a']; }
  const_reference operator[] (int i) const { return edge[c - 'a']; }
  void push(int x) { accept.push_back(x); }
  bool find(int x) const {
    return find(begin(accept), end(accept), x) != end(accept);
  }
};
