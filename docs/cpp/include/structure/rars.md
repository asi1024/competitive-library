## rars.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/rars.cpp)

{% highlight cpp %}
template <typename T>
class RARS {
  FenwickTree<T> bit1, bit2;
public:
  RARS(int n) : bit1(n+1), bit2(n+1) {}
  void add(int l, int r, T val) {
    bit1.add(l, -val * l); bit2.add(l,  val);
    bit1.add(r,  val * r); bit2.add(r, -val);
  }
  T sum(int l, int r) const {
    T rsum = bit1.sum(r) + bit2.sum(r) * r;
    T lsum = bit1.sum(l) + bit2.sum(l) * l;
    return rsum - lsum;
  }
};
{% endhighlight %}

- [Back](../../..)
