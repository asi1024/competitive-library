---
title: "euler_tour.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/euler_tour.cpp)

{% highlight cpp %}
#include "../graph/lca.cpp"
#include "../graph/traversal.cpp"
#include "segment_tree.cpp"

template <class Group> class EulerTour {
public:
  using value_type = typename Group::value_type;

private:
  const int size_;
  SegmentTree<Group> up, down;
  std::vector<int> pre, post;

public:
  template <typename edge_t>
  EulerTour(const graph_t<edge_t> &g, int root) :
    size_(g.size()), up(size_ * 2), down(size_ * 2) {
    std::tie(pre, post) = traversal(g, root);
  }

  void update(int node, const value_type &value) {
    assert(0 <= node && node < size_);  // assertion
    value_type inv = Group::inv(value);
    up.update(pre[node], inv);
    up.update(post[node], value);
    down.update(pre[node], value);
    down.update(post[node], inv);
  }

  value_type query(const LCA &lca, int l, int r) const {
    assert(0 <= l && l < size_);  // assertion
    assert(0 <= r && r < size_);  // assertion
    int p = lca.query(l, r);
    value_type res1 = up.query(post[l], post[p]);
    value_type res2 = down.query(pre[p], pre[r] + 1);
    return Group::op(res1, res2);
  }
};
{% endhighlight %}

### Includes

- [lca.cpp](../graph/lca)
- [traversal.cpp](../graph/traversal)
- [segment_tree.cpp](segment_tree)

[Back](../..)
