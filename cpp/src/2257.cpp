#include <bits/stdc++.h>

#include "../include/math/mod.cpp"

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

using Mod = Modulo<mod, true>;

struct AhoCorasick {
  static const int SIZE = 128;
  struct State {
    int index, next[SIZE];
    vector<int> accept;
    State(int index) : index(index) { memset(next, -1, sizeof(next)); }
  };

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

  pair<int,int> query(string &t, int from) {
    int index = from;
    int match = 0;
    REP(i,t.size()) {
      int c = t[i];
      index = sub(index, c);
      match += pma[index].accept.size();
    }
    return make_pair(match, index);
  }
  
};

map<string,int> dict_memo;
vector<string> dict_str;

int dict(const string &s) {
  if (dict_memo.count(s)) return dict_memo[s];
  int res = dict_str.size();
  dict_str.push_back(s);
  return dict_memo[s] = res;
}

const int BLOCK = 21;

vector<int> g[512];
Mod dp[BLOCK][512][610][2];
int is_match[512][610];
int next_node[512][610];

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha;
  cout.imbue(loc);
  int N, M, K;
  while (cin >> N >> M >> K, N) {
    REP(i,512) g[i].clear();
    dict_str.clear();
    dict_memo.clear();
    vector<int> from(N), to(N);
    vector<string> season(K);
    REP(i,N) {
      string s, t;
      cin >> s >> t;
      from[i] = dict(s);
      to[i] = dict(t);
      g[from[i]].push_back(to[i]);
    }
    const int n = dict_str.size();
    REP(i,n) g[n].push_back(i);
    REP(i,K) cin >> season[i];
    AhoCorasick aho(season);
    REP(i,dict_str.size()) REP(j,aho.pma.size()) {
      tie(is_match[i][j], next_node[i][j]) = aho.query(dict_str[i], j);
    }
    REP(i,BLOCK) REP(j,512) REP(k,610) REP(l,2) dp[i][j][k][l] = 0;
    dp[0][n][0][0] = 1;
    // M = 2;
    REP(i,M) {
      REP(from,n+1) REP(k,aho.pma.size()) {
        // cout << i << " " << from << " " << k << " " << 0 << " " << int(dp[i%BLOCK][from][k][0]) << endl;
        // cout << i << " " << from << " " << k << " " << 1 << " " << int(dp[i%BLOCK][from][k][1]) << endl;
        for (int to: g[from]) {
          int len = dict_str[to].size();
          if (is_match[to][k] >= 2) continue;
          if (is_match[to][k]) {
            dp[(i+len)%BLOCK][to][next_node[to][k]][1] += dp[i%BLOCK][from][k][0];
          }
          else {
            dp[(i+len)%BLOCK][to][next_node[to][k]][0] += dp[i%BLOCK][from][k][0];
            dp[(i+len)%BLOCK][to][next_node[to][k]][1] += dp[i%BLOCK][from][k][1];
          }
        }
      }
      REP(j,n+1) REP(k,aho.pma.size()) REP(l,2) dp[i%BLOCK][j][k][l] = 0;
    }
    Mod res = 0;
    REP(j,n+1) REP(k,aho.pma.size()) {
      res += dp[M%BLOCK][j][k][1];
    }
    cout << int(res) << endl;
  }
  return 0;
}
