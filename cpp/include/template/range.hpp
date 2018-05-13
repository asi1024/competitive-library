class range {
  class index_type {
    int x;
  public:
    index_type(int x) : x(x) {}
    int operator*() const { return x; }
    bool operator!=(index_type &r) { return x < r.x; }
    void operator++() { ++x; }
  };
  index_type i, n;
public:
  range(int n) : i(0), n(n) {}
  range(int i, int n) : i(i), n(n) {}
  index_type &begin() { return i; }
  index_type &end() { return n; }
};
