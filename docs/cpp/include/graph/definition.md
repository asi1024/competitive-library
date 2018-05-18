{% include mathjax.html %}

## add_edge

{% highlight cpp %}
void add_edge(graph_t< edge_t > &g, int from, int to, Args... args);
{% endhighlight %}

## add_edge

{% highlight cpp %}
std::enable_if<has_capacity<edge_t>::value, void>::type add_edge(graph_t< edge_t > &g, int from, int to, typename edge_t::capacity_type cap, Args... args);
{% endhighlight %}

## Member functions

### [1] (constructor)
{% highlight cpp %}
graph_t();
graph_t(int n);
{% endhighlight %}


---------------------------------------

### [2] begin
{% highlight cpp %}
begin();
{% endhighlight %}


---------------------------------------

### [3] end
{% highlight cpp %}
end();
{% endhighlight %}


---------------------------------------

### [4] operator[]
{% highlight cpp %}
operator[](int x);
operator[](int x) const;
{% endhighlight %}


---------------------------------------

### [5] push_back
{% highlight cpp %}
void push_back(const std::vector< edge_t > &es);
{% endhighlight %}


---------------------------------------

### [6] size
{% highlight cpp %}
int size() const;
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/definition.hpp)

{% highlight cpp %}
#include "../template/const_value.hpp"
#include "../template/includes.hpp"

template <class T> class has_capacity {
  template <class U> static constexpr bool check(typename U::capacity_type *) {
    return true;
  }

  template <class U> static constexpr bool check(...) { return false; }

public:
  static constexpr bool value = check<T>(nullptr);
};

template <class edge_t> class graph_t {
  std::vector<std::vector<edge_t>> g;

public:
  using reference = std::vector<edge_t> &;
  using const_reference = const std::vector<edge_t> &;
  using iterator = typename std::vector<edge_t>::iterator;
  graph_t() : g(0) { ; }
  graph_t(int n) : g(n) { ; }
  int size() const { return g.size(); }
  void push_back(const std::vector<edge_t> &es) { g.push_back(es); }
  reference operator[](int x) { return g[x]; }
  const_reference operator[](int x) const { return g[x]; }
  iterator &begin() { return begin(g); }
  iterator &end() { return end(g); }
};

template <typename edge_t, class... Args>
void add_edge(graph_t<edge_t> &g, int from, int to, Args... args) {
  g[from].emplace_back(from, to, args...);
}

template <typename edge_t, class... Args>
typename std::enable_if<has_capacity<edge_t>::value, void>::type
add_edge(graph_t<edge_t> &g, int from, int to,
         typename edge_t::capacity_type cap, Args... args) {
  g[from].emplace_back(from, to, (int)g[to].size(), cap, args...);
  g[to].emplace_back(to, from, (int)g[from].size() - 1,
                     zero<typename edge_t::capacity_type>(), args...);
}
{% endhighlight %}

### Includes

- [const_value.hpp](../template/const_value)
- [includes.hpp](../template/includes)

[Back](../..)
