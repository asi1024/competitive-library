#pragma once

#include "../template/includes.hpp"

class UnionFind {
  std::vector<int> p;

public:
  /// @brief
  /// $0$ から $n - 1$ までそれぞれに対して，その要素だけを格納した集合を作る．
  /// @complexity $O(n)$
  UnionFind(int n) : p(n, -1) {}

  /// @brief
  /// $x$ を含む集合の代表元を返す．
  /// @complexity amortized $O(\\alpha(n))$
  int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }

  /// @brief
  /// $x$ と $y$ が同一の集合に属するかどうかを返す．
  /// @complexity amortized $O(\\alpha(n))$
  bool same(int x, int y) { return root(x) == root(y); }

  /// @brief
  /// $x$ を含む集合と $y$ を含む集合を併合する．
  /// 既に $x$ を含む集合と $y$ を含む集合が同じ集合である場合は false を返し，
  /// そうでない場合は true を返す．
  /// @complexity amortized $O(\\alpha(n))$
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y)
      return false;
    if (p[y] < p[x])
      std::swap(x, y);
    if (p[x] == p[y])
      --p[x];
    p[y] = x;
    return true;
  }
};
