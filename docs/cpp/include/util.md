## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/util.hpp)

{% highlight cpp %}
#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstring>
#include <functional>
#include <map>
#include <numeric>
#include <iostream>
#include <iterator>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

using ll = long long;
using ld = long double;

template<typename T> T inf;
template<> constexpr int inf<int> = 1e9;
template<> constexpr ll inf<ll> = 1e18;
template<> constexpr ld inf<ld> = 1e30;
{% endhighlight %}

[Back](..)
