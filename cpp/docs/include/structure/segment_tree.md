{% include mathjax.html %}

### Usage

{% highlight cpp %}
(1) SegmentTree<Monoid>(int n);
(2) SegmentTree<Monoid>(int n, const Monoid::type& init);
(3) SegmentTree<Monoid>(const std::vector<Monid::type>& init);
(4) int size() const;
(5) void update(int p, const Monoid::type& val);
(6) Monoid::type query(int l, int r) const;
{% endhighlight %}

- (1): 長さ $n$ の Monoid::type の列を初期値 Monoid::id() で作る．
  - ただし，Monoid::id() はモノイドの単位元を返す関数．
- (2): 長さ $n$ の Monoid::type の列を初期値 init で作る．
- (3): 列 init を作る．
- (4): 列の長さを返す．
- (5): 列の $p$ 番目の値を val に変更する．
- (6): $a_l \cdot a_{l + 1} \cdot \ldots \cdot a_{r - 1}$ の値を返す．
  - ただし，モノイドの二項演算 $\cdot$ は Monoid::op で定義する．

### Time Complexity
- (1): $O(n)$
- (2): $O(n)$
- (3): $O(n)$
- (4): $O(1)$
- (5): $O(\log(n))$
- (6): $O(\log(n))$
