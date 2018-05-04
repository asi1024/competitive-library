## chmin

{% highlight cpp %}
T& chmin(T &a, const T &b);
{% endhighlight %}

## chmax

{% highlight cpp %}
T& chmax(T &a, const T &b);
{% endhighlight %}

## main

{% highlight cpp %}
int main();
{% endhighlight %}

## Member functions

### [1] do_falsename
{% highlight cpp %}
string_type do_falsename() const;
string_type do_falsename() const;
string_type do_falsename() const;
{% endhighlight %}


---------------------------------------

### [2] do_truename
{% highlight cpp %}
string_type do_truename() const;
string_type do_truename() const;
string_type do_truename() const;
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/template.cpp)

{% highlight cpp %}
#include <algorithm>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <vector>

/* -------------------------------- Template -------------------------------- */

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

template<typename T> T inf;
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

[Back](../..)
