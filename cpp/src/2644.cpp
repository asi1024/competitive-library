#include "../include/string/suffix_array.cpp"
 
using namespace std;
 
int main() {
  string str, a, b;
  int N;
  cin >> str;
  SuffixArray<string> sa(str);
  SegmentTree<RMQ> seg1(sa.n + 1), seg2(sa.n + 1);
  for (int i = 0; i <= sa.n; ++i) seg1.update(i, sa.sa[i]);
  for (int i = 0; i <= sa.n; ++i) seg2.update(i, -sa.sa[i]);
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> a >> b;
    int alen = a.size(), blen = b.size();
    int lpos = seg1.query(sa.lower_bound(a), sa.upper_bound(a));
    int rpos = -seg2.query(sa.lower_bound(b), sa.upper_bound(b));
    if (min(lpos, rpos) == -1) cout << 0 << endl;
    else if (lpos + alen > rpos + blen || rpos < lpos) cout << 0 << endl;
    else cout << rpos - lpos + blen << endl;
  }
  return 0;
}
