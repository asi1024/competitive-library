## DSL_2_A.1.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/DSL_2_A.1.cpp)

### Includes

- [starry_sky_tree.cpp](../include/structure/starry_sky_tree)

{% highlight cpp %}
#include "../include/structure/starry_sky_tree.cpp"

int main() {
  int n, q, com, x, y;
  scanf("%d%d", &n, &q);
  StarrySkyTree<ll> seg(n);
  seg.add(0, n, INT_MAX);
  while (q--) {
    scanf("%d%d%d", &com, &x, &y);
    if (com) printf("%lld\n", seg.minimum(x, y + 1));
    else {
      int val = seg.minimum(x, x + 1);
      seg.add(x, x + 1, y - val);
    }
  }
  return 0;
}
{% endhighlight %}

[Back](../..)
