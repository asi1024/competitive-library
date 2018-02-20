{% include mathjax.html %}

### Usage

代数系をクラスで定義して，以下のようにテンプレート引数を用いて渡す．

{% highlight cpp %}
class Monoid
(1) typename type;
(2) static type id();
(3) static type op(type l, type r);
{% endhighlight %}

- (1): Monoid のデータ型
- (2): Monoid の単位元を返す定数関数
- (3): Monoid の二項演算．この演算は結合則を満たす必要がある．

{% highlight cpp %}
(1) SegmentTree(vector<Monoid::type> vec);
(2) SegmentTree(const int count, Monoid::type value = Monoid::id());
(3) int size() const;
(4) void update(int pos, Monoid::type &value);
(5) Monoid::type query(int l, int r) const;
{% endhighlight %}

- (1): vector<T> 型の列 vec を表現するセグメント木を作る．
- (2): 長さ count のセグメント木を作り，全ての要素を value で初期化する．
- (3): セグメント木のサイズを返す．
- (4): p 番目の要素を val に更新する．
  - p はセグメント木のサイズ未満の非負整数である必要がある．
  - その範囲を超えた場合は例外を送出する．
- (5): セグメント木の区間 [l, r) を演算 op で畳み込んだ値を返す．
  - すなわち，$a_l \cdot a_{l+1} \cdot \ldots \cdot a_{r-1}$ を返す．
  - $l = r$ の場合は Monoid::id() を返す．

### Time Complexity
Monoid::op にかかる時間を定数時間とすると，
- (1): $O(n)$
- (2): $O(n)$
- (3): $O(1)$
- (4): $O(\log(n))$
- (5): $O(\log(n))$
