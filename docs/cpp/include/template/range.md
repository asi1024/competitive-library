{% include mathjax.html %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
range(int n_);
range(int i_, int n_);
{% endhighlight %}


---------------------------------------

### [2] begin
{% highlight cpp %}
index_type & begin();
{% endhighlight %}


---------------------------------------

### [3] end
{% highlight cpp %}
index_type & end();
{% endhighlight %}


---------------------------------------

## Member functions

### [1] index_type
{% highlight cpp %}
index_type(int x_);
{% endhighlight %}


---------------------------------------

### [2] operator!=
{% highlight cpp %}
bool operator!=(index_type &r);
{% endhighlight %}


---------------------------------------

### [3] operator*
{% highlight cpp %}
int operator*() const;
{% endhighlight %}


---------------------------------------

### [4] operator++
{% highlight cpp %}
void operator++();
{% endhighlight %}


---------------------------------------

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
