{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/ITP1_7_D.cpp)

{% highlight cpp %}
#include "../include/math/matrix.cpp"

#define REP(i, n) for (int i = 0; i < (n); ++i)

int main() {
  int N, M, L;
  scanf("%d%d%d", &N, &M, &L);
  Matrix<ll> A(N, M), B(M, L);
  REP(i, N) REP(j, M) cin >> A[i][j];
  REP(i, M) REP(j, L) cin >> B[i][j];
  auto res = A * B;
  REP(i, N) REP(j, L) cout << res[i][j] << " \n"[j == L - 1];
  return 0;
}
{% endhighlight %}

### Includes

- [matrix.cpp](../include/math/matrix)

[Back](..)
