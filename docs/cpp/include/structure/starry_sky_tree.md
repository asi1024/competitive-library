{% include mathjax.html %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
StarrySkyTree(int count);
{% endhighlight %}


---------------------------------------

### [2] query
{% highlight cpp %}
T query(int l, int r) const;
{% endhighlight %}


---------------------------------------

### [3] update
{% highlight cpp %}
void update(int l, int r, const T &val);
{% endhighlight %}


---------------------------------------

{% include mathjax.html %}

### Usage

{% highlight cpp %}
(1) StarrySkyTree<typename T>(int count);
(2) T update(int l, int r, const T& value);
(3) T query(int l, int r) const;
{% endhighlight %}

- (1): 長さ count の列を作り，全ての要素を 0 で初期化する．
- (2): 区間 [l, r) 番目の要素に値 value を加える．
- (3): 区間 [l, r) 番目の範囲の最小値を求める．

### Time Complexity
- (1): $O(n)$
- (2): $O(\log(n))$
- (3): $O(\log(n))$

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/starry_sky_tree.cpp)

{% highlight cpp %}
template <typename T>
class StarrySkyTree {
  const int n;
  vector<T> data, lazy;
  int expand(int m) const { return m == 1 ? m : expand((m + 1) / 2) * 2; }
public:
  StarrySkyTree(int count) : n(expand(count)), data(n * 2, 0), lazy(n * 2, 0) {}
  void update(int l, int r, const T &val) {
    l += n; r += n;
    const int left = l, right = r;
    while (l != r) {
      if (l % 2) { lazy[l] += val; data[l++] += val; }
      if (r % 2) { lazy[--r] += val; data[r] += val; }
      l /= 2; r /= 2;
    }
    l = left; r = right - 1;
    while (l /= 2, r /= 2) {
      data[l] = min(data[l * 2], data[l * 2 + 1]) + lazy[l];
      data[r] = min(data[r * 2], data[r * 2 + 1]) + lazy[r];
    }
  }
  T query(int l, int r) const {
    l += n; r += n;
    T res1 = inf<T>, res2 = inf<T>;
    while (l != r) {
      if (l % 2) res1 = min(res1, data[l++]);
      if (r % 2) res2 = min(res2, data[--r]);
      l /= 2; r /= 2; res1 += lazy[l - 1]; res2 += lazy[r];
    }
    --l;
    while (l /= 2, r /= 2) { res1 += lazy[l]; res2 += lazy[r]; }
    return min(min(res1, res2), inf<T>);
  }
  using value_type = T;
  using update_type = T;
};
{% endhighlight %}

[Back](../..)
