## SlideMin

### Member functions

#### (constructor)
{% highlight cpp %}
SlideMin();
{% endhighlight %}


#### minimum
{% highlight cpp %}
T minimum() const;
{% endhighlight %}


#### pop
{% highlight cpp %}
void pop();
{% endhighlight %}


#### push
{% highlight cpp %}
void push(T val);
{% endhighlight %}


#### size
{% highlight cpp %}
int size() const;
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/slide_min.cpp)

{% highlight cpp %}
template <typename T>
struct SlideMin {
  deque<pair<int,T>> deq;
  int l, r;
  SlideMin() : l(0), r(0) {;}
  void push(T val) {
    while (!deq.empty() && deq.back().second >= val) deq.pop_back();
    deq.emplace_back(r, val);
    ++r;
  }
  void pop() {
    assert (!deq.empty());
    if (deq.front().first <= l) deq.pop_front();
    ++l;
  }
  int size() const { return r - l; }
  T minimum() const { return deq.front().second; }
};
{% endhighlight %}

[Back](../..)
