## eratosthenes.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/math/eratosthenes.cpp)

{% highlight cpp %}
const int Prime_N = 1024000;

bitset<Prime_N> is_prime;

vector<int> primes() {
  is_prime.set();
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i * i < Prime_N; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j < Prime_N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  vector<int> res;
  for (int i = 2; i < Prime_N; ++i) {
    if (is_prime[i]) res.push_back(i);
  }
  return res;
}
{% endhighlight %}

- [Back](../../..)
