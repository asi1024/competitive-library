{% include mathjax.html %}

## main

{% highlight cpp %}
int main();
{% endhighlight %}

## Member functions

### [1] do_falsename
{% highlight cpp %}
string_type do_falsename() const;
string_type do_falsename() const;
string_type do_falsename() const;
{% endhighlight %}


---------------------------------------

### [2] do_truename
{% highlight cpp %}
string_type do_truename() const;
string_type do_truename() const;
string_type do_truename() const;
{% endhighlight %}


---------------------------------------

## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/template.cpp)

{% highlight cpp %}
#include "includes.hpp"
#include "macros.hpp"
#include "range.hpp"
#include "const_value.hpp"
#include "misc.hpp"

using namespace std;

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha;
  cout.imbue(loc);

  return 0;
}
{% endhighlight %}

### Includes

- [includes.hpp](includes)
- [macros.hpp](macros)
- [range.hpp](range)
- [const_value.hpp](const_value)
- [misc.hpp](misc)

[Back](../..)
