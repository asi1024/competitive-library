#include "../include/graph/bipartite_matching.cpp"

int main() {
  int X, Y, E, x, y;
  scanf("%d%d%d", &X, &Y, &E);
  BipartiteMatching mat(X, Y);
  while (E--) {
    scanf("%d%d", &x, &y);
    mat.add(x, y);
  }
  printf("%d\n", mat.maximum_matching());
  return 0;
}
