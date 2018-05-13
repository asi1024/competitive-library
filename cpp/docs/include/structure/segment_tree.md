## Type requirements

[モノイド](https://ja.wikipedia.org/wiki/モノイド)をクラスで定義して，以下のようにテンプレート引数を用いて渡す．

{% highlight cpp %}
class Monoid
(1) typename type;
(2) static type id();
(3) static type op(const type& l, const type& r);
{% endhighlight %}

- (1): Monoid のデータ型
- (2): Monoid の単位元を返す定数関数
- (3): Monoid の二項演算．この演算は結合則を満たす必要がある．
