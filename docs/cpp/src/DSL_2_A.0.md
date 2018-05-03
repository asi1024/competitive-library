### Includes

- [segment_tree.cpp](../include/structure/segment_tree)

{% highlight cpp %}
#include "../include/structure/segment_tree.cpp"

int main() {
  int n, q, com, x, y;
  scanf("%d%d", &n, &q);
  SegmentTree<RMQ> seg(n);
  while (q--) {
    scanf("%d%d%d", &com, &x, &y);
    if (com) printf("%d\n", seg.query(x, y + 1));
    else seg.update(x, y);
  }
  return 0;
}
{% endhighlight %}

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/DSL_2_A.0.cpp)

[Back](..)
