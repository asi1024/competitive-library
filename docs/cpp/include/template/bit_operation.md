{% include mathjax.html %}

## log2ceil

{% highlight cpp %}
int log2ceil(int n);
{% endhighlight %}

## log2ceil

{% highlight cpp %}
int log2ceil(long long n);
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/bit_operation.cpp)

{% highlight cpp %}
int log2ceil(int n) {
  --n;
  n |= n >> 16;
  n |= n >> 8;
  n |= n >> 4;
  n |= n >> 2;
  n |= n >> 1;
  return n + 1;
}

int log2ceil(long long n) {
  --n;
  n |= n >> 32;
  n |= n >> 16;
  n |= n >> 8;
  n |= n >> 4;
  n |= n >> 2;
  n |= n >> 1;
  return n + 1;
}
{% endhighlight %}

[Back](../..)
