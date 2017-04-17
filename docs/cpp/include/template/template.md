## template.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/template.cpp)

{% highlight cpp %}
#include <bits/stdc++.h>

/* -------------------------------- Template -------------------------------- */

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

template<typename T> T inf = [](){ assert(false); };
template<> constexpr int inf<int> = 1e9;
template<> constexpr ll inf<ll> = 1e18;
template<> constexpr ld inf<ld> = 1e30;

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

/* -------------------------------- Library -------------------------------- */

/* ---------------------------------- Main ---------------------------------- */

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha;
  cout.imbue(loc);

  return 0;
}
{% endhighlight %}

- [Back](../../..)
