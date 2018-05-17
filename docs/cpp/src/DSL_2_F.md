{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/DSL_2_F.cpp)

{% highlight cpp %}
#include "../include/structure/segment_tree_lazy.cpp"

int main() {
  int n, q, com, s, t, x;
  scanf("%d%d", &n, &q);
  SegmentTreeLazy<RangeUpdate> seg(n);
  while (q--) {
    scanf("%d", &com);
    if (com) {
      scanf("%d%d", &s, &t);
      printf("%d\n", seg.query(s, t + 1));
    } else {
      scanf("%d%d%d", &s, &t, &x);
      seg.update(s, t + 1, x);
    }
  }
  return 0;
}
{% endhighlight %}

### Includes

- [segment_tree_lazy.cpp](../include/structure/segment_tree_lazy)

[Back](..)
