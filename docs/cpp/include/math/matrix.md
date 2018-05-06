{% include mathjax.html %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
Vec(int n);
Vec(int n, const T &val);
Vec(const vector< T > &w);
{% endhighlight %}


---------------------------------------

### [2] begin
{% highlight cpp %}
begin() const noexcept;
begin() noexcept;
{% endhighlight %}


---------------------------------------

### [3] concat
{% highlight cpp %}
void concat(const Vec< T > &r);
{% endhighlight %}


---------------------------------------

### [4] dot
{% highlight cpp %}
T dot(const Vec< T > &r) const;
{% endhighlight %}


---------------------------------------

### [5] end
{% highlight cpp %}
end() const noexcept;
end() noexcept;
{% endhighlight %}


---------------------------------------

### [6] norm
{% highlight cpp %}
T norm() const;
{% endhighlight %}


---------------------------------------

### [7] operator+
{% highlight cpp %}
operator+(const Vec< T > &r) const;
{% endhighlight %}


---------------------------------------

### [8] operator+=
{% highlight cpp %}
operator+=(const Vec< T > &r);
{% endhighlight %}


---------------------------------------

### [9] operator-
{% highlight cpp %}
operator-() const;
operator-(const Vec< T > &r) const;
{% endhighlight %}


---------------------------------------

### [10] operator-=
{% highlight cpp %}
operator-=(const Vec< T > &r);
{% endhighlight %}


---------------------------------------

### [11] operator[]
{% highlight cpp %}
operator[](int i);
operator[](int i) const;
{% endhighlight %}


---------------------------------------

### [12] push_back
{% highlight cpp %}
void push_back(const T &r);
{% endhighlight %}


---------------------------------------

### [13] size
{% highlight cpp %}
int size() const noexcept;
{% endhighlight %}


---------------------------------------

## Member functions

### [1] (constructor)
{% highlight cpp %}
Matrix(int n, int m, const T &val);
{% endhighlight %}


---------------------------------------

### [2] X
{% highlight cpp %}
int X() const;
{% endhighlight %}


---------------------------------------

### [3] Y
{% highlight cpp %}
int Y() const;
{% endhighlight %}


---------------------------------------

### [4] concat_below
{% highlight cpp %}
void concat_below(const Vec< T > &r);
void concat_below(const Matrix< T > &r);
{% endhighlight %}


---------------------------------------

### [5] concat_right
{% highlight cpp %}
void concat_right(const Vec< T > &r);
void concat_right(const Matrix< T > &r);
{% endhighlight %}


---------------------------------------

### [6] det
{% highlight cpp %}
T det() const;
{% endhighlight %}


---------------------------------------

### [7] operator*
{% highlight cpp %}
operator*(const Matrix< T > &r) const;
operator*(const Vec< T > &r) const;
{% endhighlight %}


---------------------------------------

### [8] operator*=
{% highlight cpp %}
operator*=(const Matrix< T > &r);
{% endhighlight %}


---------------------------------------

### [9] operator^
{% highlight cpp %}
operator^(ll n) const;
{% endhighlight %}


---------------------------------------

### [10] rank
{% highlight cpp %}
int rank() const;
{% endhighlight %}


---------------------------------------

### [11] transpose
{% highlight cpp %}
transpose() const;
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/math/matrix.cpp)

{% highlight cpp %}
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
  void push_back(const T &r) { v.push_back(r); }
  void concat(const Vec<T> &r) { v.insert(v.end(), r.begin(), r.end()); }
};

template<typename T>
class Matrix : public Vec<Vec<T>> {
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
  Vec<T> operator*(const Vec<T> &r) const {
    const int row = Y(), col = r.Y();
    assert (r.size() == col);
    Vec<T> res(row);
    for (int i = 0; i < row; ++i) {
      res[i] = (*this)[i].dot(r);
    }
    return res;
  }
  Matrix<T> &operator*=(const Matrix<T> &r) { return *this = *this * r; }
  Matrix<T> operator^(ll n) const {
    const int m = Y();
    assert (m == X());
    Matrix<T> A = *this, res(m, m, 0);
    for (int i = 0; i < m; ++i) res[i][i] = 1;
    while (n > 0) {
      if (n % 2) res *= A;
      A = A * A;
      n /= 2;
    }
    return res;
  }
  void concat_right(const Vec<T> &r) {
    const int n = Y();
    assert (n == r.size());
    for (int i = 0; i < n; ++i) {
      (*this)[i].push_back(r[i]);
    }
  }
  void concat_right(const Matrix<T> &r) {
    const int n = Y();
    assert (n == r.Y());
    for (int i = 0; i < n; ++i) {
      (*this)[i].concat(r[i]);
    }
  }
  void concat_below(const Vec<T> &r) {
    assert (Y() == 0 || X() == r.size());
    this->push_back(r);
  }
  void concat_below(const Matrix<T> &r) {
    assert (Y() == 0 || X() == r.X());
    for (Vec<T> i: r) (*this).push_back(i);
  }
  int rank() const {
    Matrix<T> A = *this;
    if (Y() == 0) return 0;
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
    const int n = Y();
    if (n == 0) return 1;
    assert (Y() == X());
    Matrix<T> A = *this;
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
{% endhighlight %}

[Back](../..)
