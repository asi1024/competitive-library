{% include mathjax.html %}

## Member functions

### [1] do_falsename
{% highlight cpp %}
string_type do_falsename() const;
{% endhighlight %}


---------------------------------------

### [2] do_truename
{% highlight cpp %}
string_type do_truename() const;
{% endhighlight %}


---------------------------------------

## Member functions

### [1] (constructor)
{% highlight cpp %}
Initialize();
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/initialize.cpp)

{% highlight cpp %}
#include "includes.hpp"

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

const Initialize init;
{% endhighlight %}

### Includes

- [includes.hpp](includes)

[Back](../..)
