{% include mathjax.html %}

## area

{% highlight cpp %}
ld area(const Polygon &g);
{% endhighlight %}

## is_in_polygon

{% highlight cpp %}
int is_in_polygon(const Polygon &g, Point p);
{% endhighlight %}

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/geometry/polygon.cpp)

{% highlight cpp %}
#include "intersect.cpp"

ld area(const Polygon &g) {
  ld res = 0;
  int n = g.size();
  for (int i = 0; i < n; ++i) {
    res += cross(at(g, i), at(g, i + 1));
  }
  return res / 2;
}

int is_in_polygon(const Polygon &g, Point p) {
  // in  ->  1
  // on  ->  0
  // out -> -1
  int n = g.size();
  ld sum = 0;
  for (int i = 0; i < n; i++) {
    if (isis_sp(Segment(at(g, i), at(g, i + 1)), p))
      return 0; // on
    sum += arg((at(g, i + 1) - p) / (at(g, i) - p));
  }
  return abs(sum) > 0.5 ? 1 : -1;
}
{% endhighlight %}

### Includes

- [intersect.cpp](intersect)

[Back](../..)
