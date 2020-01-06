---
title: "initialize.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/initialize.cpp)

{% highlight cpp %}
#include "includes.cpp"

struct yes_no : std::numpunct<char> {
  string_type do_truename() const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

struct Initialize {
  Initialize() {
    std::locale loc(std::locale(), new yes_no);
    std::cout << std::boolalpha << std::setprecision(11) << std::fixed;
    std::cout.imbue(loc);
  }
};

const Initialize initialize;
{% endhighlight %}

### Includes

- [includes.cpp](includes)

[Back](../..)
