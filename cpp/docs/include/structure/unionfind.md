```
UnionFind(int n);
```
- 0 から n - 1 までそれぞれに対して，その要素だけを格納した集合を作成する．
- 計算量: O(n)

```
int root(int x);
```
- x を含む集合の代表元を返す．
- 計算量: amortized O(α(n))

```
bool same(int x, int y);
```
- x と y が同一の集合に属するかどうかを返す．
- 計算量: amortized O(α(n))

```
bool unite(int x, int y);
```
- x を含む集合と y を含む集合を併合する．既に x を含む集合と y を含む集合が同じ集合である場合は， `false` を返し，そうでない場合は `true` を返す．
- 計算量: amortized O(α(n))
