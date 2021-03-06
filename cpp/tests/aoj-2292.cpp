#include "../include/string/manacher.cpp"
#include "../include/string/rolling_hash.cpp"

using namespace std;

using hash_t = pair<ll, ll>;

struct Ret {
  int l, r;
  ll cnt;
  Ret() : l(0), r(0), cnt(0) { ; }
  Ret(int l_, int r_, ll cnt_) : l(l_), r(r_), cnt(cnt_) { ; }
};

vector<map<hash_t, Ret>> count(const string &s) {
  const int n = s.size();
  string str = "%";
  for (char c : s) {
    str += c;
    str += '%';
  }
  vector<int> rad = manacher(str);
  RollingHash rh(s);
  vector<map<hash_t, Ret>> cnt(n + 1);
  for (int i = 1; i < int(rad.size()) - 1; ++i) {
    const int l = (i - rad[i] + 1) / 2;
    const int r = (i + rad[i] - 1) / 2;
    if (l == r) continue;
    hash_t h = rh.query(l, r);
    if (cnt[r - l].count(h))
      cnt[r - l][h].cnt += 1;
    else
      cnt[r - l][h] = Ret(l, r, 1);
  }
  for (int i = n; i >= 3; --i) {
    for (auto p : cnt[i]) {
      const int l = p.second.l + 1, r = p.second.r - 1;
      auto h = rh.query(l, r);
      if (cnt[r - l].count(h))
        cnt[r - l][h].cnt += p.second.cnt;
      else
        cnt[r - l][h] = Ret(l, r, p.second.cnt);
    }
  }
  return cnt;
}

int main() {
  string s, t;
  cin >> s >> t;
  auto res1 = count(s);
  auto res2 = count(t);
  const int n = min(res1.size(), res2.size());
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    for (auto p : res1[i]) {
      res += p.second.cnt * res2[i][p.first].cnt;
    }
  }
  cout << res << endl;
  return 0;
}
