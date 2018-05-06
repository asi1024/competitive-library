{% include mathjax.html %}

## manacher

{% highlight cpp %}
vector<int> manacher(const string_t &s);
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/string/manacher.cpp)

{% highlight cpp %}
template<typename string_t>
vector<int> manacher(const string_t &s) {
  const int n = s.size();
  vector<int> rad(n);
  int i = 0, j = 0, k = 0;
  while (i < n) {
    while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) ++j;
    rad[i] = j;
    for (k = 1; i - k >= 0 && i + k < n && k + rad[i - k] < j; ++k) {
      rad[i + k] = rad[i - k];
    }
    i += k; j -= k;
  }
  return rad;
}
{% endhighlight %}

[Back](../..)
