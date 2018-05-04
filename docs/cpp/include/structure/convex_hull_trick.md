## Member functions

### [1] add
{% highlight cpp %}
void add(Data a, Data b);
{% endhighlight %}


---------------------------------------

### [2] check
{% highlight cpp %}
bool check(pair< Data, Data > l3);
{% endhighlight %}


---------------------------------------

### [3] empty
{% highlight cpp %}
bool empty() const;
{% endhighlight %}


---------------------------------------

### [4] f
{% highlight cpp %}
Data f(int k, Data x);
{% endhighlight %}


---------------------------------------

### [5] minimum
{% highlight cpp %}
Data minimum(Data x);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/convex_hull_trick.cpp)

{% highlight cpp %}
template<class Data>
struct ConvexHullTrick {
  deque<pair<Data, Data>> l;
  bool check(pair<Data, Data> l3) {
    const auto l1 = *prev(end(l), 2);
    const auto l2 = *prev(end(l), 1);
    Data a = (l2.first - l1.first) * (l3.second - l2.second);
    Data b = (l2.second - l1.second) * (l3.first - l2.first);
    return a >= b;
  }
  bool empty() const { return l.empty(); }
  void add(Data a, Data b) {
    if (!empty()) assert (l.back().first >= a);
    pair<Data, Data> n(a, b);
    while ((int)l.size() >= 2 && check(n)) l.pop_back();
    l.emplace_back(n);
  }
  Data f(int k, Data x) { return l[k].first * x + l[k].second; }
  Data minimum(Data x) {
    assert (!empty());
    while ((int)l.size() >= 2 && f(0, x) >= f(1, x)) l.pop_front();
    return f(0, x);
  }
};
{% endhighlight %}

[Back](../..)
