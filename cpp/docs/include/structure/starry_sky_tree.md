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
