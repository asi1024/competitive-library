## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/DSL_2_A.0.cpp)

{% highlight cpp %}
#include "../include/structure/segment_tree.cpp"

struct RMQ {
  using value_type = int;
  static value_type id() { return INT_MAX; }
  static value_type op(const value_type &l, const value_type &r) {
    return std::min(l, r);
  }
};

int main() {
  int n, q, com, x, y;
  scanf("%d%d", &n, &q);
  SegmentTree<RMQ> seg(n);
  while (q--) {
    scanf("%d%d%d", &com, &x, &y);
    if (com)
      printf("%d\n", seg.query(x, y + 1));
    else
      seg.update(x, y);
  }
  return 0;
}
{% endhighlight %}

### Includes

- [segment_tree.cpp](../include/structure/segment_tree)

[Back](..)
