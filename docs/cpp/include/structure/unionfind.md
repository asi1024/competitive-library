{% include mathjax.html %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
UnionFind(int n);
UnionFind(int n);
{% endhighlight %}


---------------------------------------

### [2] root
{% highlight cpp %}
int root(int x);
int root(int x);
{% endhighlight %}


---------------------------------------

### [3] same
{% highlight cpp %}
bool same(int x, int y);
bool same(int x, int y);
{% endhighlight %}


---------------------------------------

### [4] unite
{% highlight cpp %}
bool unite(int x, int y);
bool unite(int x, int y);
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/structure/unionfind.cpp)

{% highlight cpp %}
class UnionFind {
  vector<int> p;
public:
  UnionFind (int n) : p(n, -1) {}
  int root(int x) {
    return p[x] < 0 ? x : p[x] = root(p[x]);
  }
  bool same(int x, int y) {
    return root(x) == root(y);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (p[y] < p[x]) swap(x, y);
    if (p[x] == p[y]) --p[x];
    p[y] = x;
    return true;
  }
};
{% endhighlight %}

{% include mathjax.html %}

### Usage

{% highlight cpp %}
(1) UnionFind(int n);
(2) int root(int x);
(3) bool same(int x, int y);
(4) bool unite(int x, int y);
{% endhighlight %}

- (1): $0$ から $n - 1$ までそれぞれに対して，その要素だけを格納した集合を作る．
- (2): $x$ を含む集合の代表元を返す．
- (3): $x$ と $y$ が同一の集合に属するかどうかを返す．
- (4): $x$ を含む集合と $y$ を含む集合を併合する．
  - 既に $x$ を含む集合と $y$ を含む集合が同じ集合である場合は，
    false を返し，そうでない場合は true を返す．

### Time Complexity
- (1): $O(n)$
- (2): amortized $O(\alpha(n))$
- (3): amortized $O(\alpha(n))$
- (4): amortized $O(\alpha(n))$

[Back](../..)
