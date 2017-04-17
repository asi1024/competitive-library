## DSL_2_A.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/src/DSL_2_A.cpp)

### Include

- [segment_tree.cpp](../include/structure/segment_tree)

{% highlight cpp %}
#include "../include/structure/segment_tree.cpp"

struct RMQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(const type &l, const type &r) { return min(l, r); }
};

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

- [Back](../..)
