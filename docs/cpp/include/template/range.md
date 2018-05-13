{% include mathjax.html %}



## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/range.hpp)

{% highlight cpp %}
class range {
  class index_type {
    int x;
  public:
    index_type(int x_) : x(x_) {}
    int operator*() const { return x; }
    bool operator!=(index_type &r) { return x < r.x; }
    void operator++() { ++x; }
  };
  index_type i, n;
public:
  range(int n_) : i(0), n(n_) {}
  range(int i_, int n_) : i(i_), n(n_) {}
  index_type &begin() { return i; }
  index_type &end() { return n; }
};
{% endhighlight %}

[Back](../..)
