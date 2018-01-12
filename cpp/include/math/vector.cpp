#pragma once

#include "../util.hpp"

template<typename T>
class Vec {
protected:
  using iterator = typename vector<T>::iterator;
  using const_iterator = typename vector<T>::const_iterator;
  using reference = T&;
  using const_reference = const T&;
  vector<T> v;
  template<typename Unop> Vec<T> unop_new(Unop op) const {
    Vec<T> res(v.size());
    transform(begin(v), end(v), res.begin(), op);
    return res;
  }
  template<typename Binop> Vec<T>& binop(const Vec<T> &r, Binop op) {
    transform(r.begin(), r.end(), v.begin(), v.begin(), op);
    return *this;
  }
  template<typename Binop> Vec<T> binop_new(const Vec<T> &r, Binop op) const {
    Vec<T> res(v.size());
    transform(r.begin(), r.end(), v.begin(), res.begin(), op);
    return res;
  }
public:
  Vec(int n) : v(n) {}
  Vec(int n, const T &val) : v(n, val) {}
  Vec(const vector<T> &w) : v(w) {}
  int size() const noexcept { return v.size(); }
  const_iterator begin() const noexcept { return v.begin(); }
  const_iterator end() const noexcept { return v.end(); }
  iterator begin() noexcept { return v.begin(); }
  iterator end() noexcept { return v.end(); }
  reference operator[] (int i) { return v[i]; }
  const_reference operator[] (int i) const { return v[i]; }
  Vec<T> operator-() const { return unop_new([](T val){ return -val; }); };
  Vec<T> &operator+=(const Vec<T> &r) {
    return binop(r, [](T x, T y) { return x + y; });
  }
  Vec<T> &operator-=(const Vec<T> &r) {
    return binop(r, [](T x, T y) { return x - y; });
  }
  Vec<T> operator+(const Vec<T> &r) const {
    return binop_new(r, [](T x, T y) { return x + y; });
  }
  Vec<T> operator-(const Vec<T> &r) const {
    return binop_new(r, [](T x, T y) { return x - y; });
  }
  T dot(const Vec<T> &r) const {
    return inner_product(v.begin(), v.end(), r.begin(), T(0));
  }
  T norm() const { return this->dot(v); }
};

template<typename T>
class Matrix : public Vec<Vec<T>> {
  bool is_zero(T dat) { return (abs(dat) < 1e-9); }
public:
  using Vec<Vec<T>>::Vec;
  Matrix(int n, int m, const T &val) : Vec<Vec<T>>::Vec(n, Vec<T>(m, val)) {}
  int Y() const { return this->size(); }
  int X() const { return (*this)[0].size(); }
  Matrix<T> transpose() const {
    const int row = Y(), col = X();
    Matrix res(col, row);
    for (int j = 0; j < col; ++j) {
      for (int i = 0; i < row; ++i) {
        res[j][i] = (*this)[i][j];
      }
    }
    return res;
  }
  Matrix<T> operator*(const Matrix<T> &r) const {
    Matrix<T> tr = r.transpose();
    const int row = Y(), col = tr.Y();
    assert (X() == tr.X());
    Matrix<T> res(row, col);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        res[i][j] = (*this)[i].dot(tr[j]);
      }
    }
    return res;
  }
  Matrix<T> &operator*=(const Matrix<T> &r) { return *this = *this * r; }
  int rank() const {
    Matrix<T> A = *this;
    const int n = Y(), m = X();
    int r = 0;
    for (int i = 0; r < n && i < m; ++i) {
      int pivot = r;
      for (int j = r+1; j < n; ++j) {
        if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
      }
      swap(A[pivot], A[r]);
      if (is_zero(A[r][i])) continue;
      for (int k = m-1; k >= i; --k) A[r][k] = A[r][k] / A[r][i];
      for(int j = r+1; j < n; ++j) {
        for(int k = m-1; k >= i; --k) {
          A[j][k] -= A[r][k] * A[j][i];
        }
      }
      ++r;
    }
    return r;
  }
  T det() const {
    Matrix<T> A = *this;
    const int n = A.size();
    T D = 1;
    for (int i = 0; i < n; ++i) {
      int pivot = i;
      for (int j = i+1; j < n; ++j) {
        if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
      }
      swap(A[pivot], A[i]);
      D = D * A[i][i] * T(i != pivot ? -1 : 1);
      if (is_zero(A[i][i])) break;
      for(int j = i+1; j < n; ++j) {
        for(int k = n-1; k >= i; --k) {
          A[j][k] -= A[i][k] * A[j][i] / A[i][i];
        }
      }
    }
    return D;
  }
};
