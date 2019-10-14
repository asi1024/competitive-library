## Implementation

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/google_code_jam.cpp)

{% highlight cpp %}
#include "template.cpp"

class GoogleCodeJam {
public:
  string case_prefix;
  void exec() const;
  GoogleCodeJam() {
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; i++) {
      case_prefix = "Case #" + std::to_string(i) + ":";
      exec();
    }
  }
};
{% endhighlight %}

### Includes

- [template.cpp](template)

[Back](../..)
