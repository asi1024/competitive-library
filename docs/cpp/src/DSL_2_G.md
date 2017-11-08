## DSL_2_G.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/DSL_2_G.cpp)

### Includes

- [rars.cpp](../include/structure/rars)

{% highlight cpp %}
#include "../include/structure/rars.cpp"

int main() {
  int n, q, com, s, t, x;
  scanf("%d%d", &n, &q);
  RARS<ll> bit(n + 1);
  while (q--) {
    scanf("%d%d%d", &com, &s, &t);
    if (com) printf("%lld\n", bit.sum(s, t + 1));
    else {
      scanf("%d", &x);
      bit.add(s, t + 1, x);
    }
  }
  return 0;
}
{% endhighlight %}

[Back](../..)
