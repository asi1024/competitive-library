## matrix.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/math/matrix.cpp)

```cpp
template <typename T> using Matrix = vector<vector<T>>;

template <typename T>
bool is_zero(T dat) { return (abs(dat) < 1e-9); }

template<typename T>
Matrix<T> transpose(const Matrix<T> &A) {
  const int n = A[0].size(), m = A.size();
  Matrix<T> res(n, vector<T>(m, 0));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      res[i][j] = A[j][i];
  return res;
}

template<typename T>
Matrix<T> operator*(const Matrix<T> &a, Matrix<T> b) {
  b = transpose(b);
  const int n = a.size(), m = b.size();
  assert (a[0].size() == b[0].size());
  Matrix<T> res(n, vector<T>(m));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      res[i][j] = dot(a[i], b[j]);
  return res;
}

template<typename T>
void operator*=(Matrix<T> &a, const Matrix<T> &b) { a = a * b; }

template<typename T>
int rankMat(Matrix<T> A) {
  const int n = A.size(), m = A[0].size();
  int r = 0;
  for (int i = 0; r < n && i < m; ++i) {
    int pivot = r;
    for (int j = r+1; j < n; ++j)
      if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
    swap(A[pivot], A[r]);
    if (is_zero(A[r][i])) continue;
    for (int k = m-1; k >= i; --k)
      A[r][k] = A[r][k] / A[r][i];
    for(int j = r+1; j < n; ++j)
      for(int k = m-1; k >= i; --k)
        A[j][k] -= A[r][k] * A[j][i];
    ++r;
  }
  return r;
}

template<typename T>
T det(Matrix<T> A) {
  const int n = A.size();
  T D = 1;
  for (int i = 0; i < n; ++i) {
    int pivot = i;
    for (int j = i+1; j < n; ++j)
      if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
    swap(A[pivot], A[i]);
    D = D * A[i][i] * T(i != pivot ? -1 : 1);
    if (is_zero(A[i][i])) break;
    for(int j = i+1; j < n; ++j)
      for(int k = n-1; k >= i; --k)
        A[j][k] -= A[i][k] * A[j][i] / A[i][i];
  }
  return D;
}
```

- [Back](https://{{ site.github.owner_name }}.github.io/competitive-library)
