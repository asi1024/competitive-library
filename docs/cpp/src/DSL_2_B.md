### Includes

- [fenwick_tree.cpp](../include/structure/fenwick_tree)

{% highlight cpp %}
#include "../include/structure/fenwick_tree.cpp"

int main() {
  int n, q, com, x, y;
  scanf("%d%d", &n, &q);
  FenwickTree<int> bit(n + 1);
  while (q--) {
    scanf("%d%d%d", &com, &x, &y);
    if (com) printf("%d\n", bit.sum(x, y + 1));
    else bit.add(x, y);
  }
  return 0;
}
{% endhighlight %}

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/DSL_2_B.cpp)

[Back](..)
