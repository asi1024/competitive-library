## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/others/cin.cpp)

{% highlight cpp %}
class fast_istream {
  bool is_space(char c) { return c < 0x21 || c > 0x7E; }
  template<typename T> void get_integer(T &var) {
    var = 0;
    T sign = 1;
    int c = getchar_unlocked();
    while (c < '0' || '9' < c) {
      if (c == '-') sign = -1;
      c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
      var = var * 10 + c - '0';
      c = getchar_unlocked();
    }
    var *= sign;
  }
public:
  inline fast_istream& operator>>(int &var) {
    get_integer(var);
    return *this;
  }
  inline fast_istream& operator>>(long long &var) {
    get_integer(var);
    return *this;
  }
  inline fast_istream& operator>>(string &var) {
    char c = getchar_unlocked();
    while (is_space(c)) {
      c = getchar_unlocked();
    }
    var = "";
    while (is_space(c)) {
      var.push_back(c);
      c = getchar_unlocked();
    }
    return *this;
  }
};

fast_istream fcin;
{% endhighlight %}

[Back](../..)
