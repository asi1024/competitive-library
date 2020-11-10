---
title: "macros.cpp"
---

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/template/macros.cpp)

{% highlight cpp %}
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
#define HHH(x) cerr << "L" << __LINE__ << ": " << #x << " = " << (x) << endl
{% endhighlight %}

[Back](../..)
