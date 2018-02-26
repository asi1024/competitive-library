{% include mathjax.html %}

### Usage

{% highlight cpp %}
(1) RARS<typename T>(int count);
(2) T add(int l, int r, const T& value);
(4) T sum(int l, int r) const;
{% endhighlight %}

- (1): 長さ count の Fenwick Tree を作り，全ての要素を 0 で初期化する．
- (2): 区間 [l, r) 番目の要素に値 value を加える．
- (3): 区間 [l, r) 番目の範囲の和を求める．

### Time Complexity
- (1): $O(n)$
- (3): $O(\log(n))$
- (4): $O(\log(n))$
