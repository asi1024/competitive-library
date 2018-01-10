## ext.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/others/ext.cpp)

{% highlight cpp %}
#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pool_allocator.h>

using namespace __gnu_cxx;
using namespace __gnu_pbds::detail;
using namespace __gnu_pbds;

template<typename Key>
using pool_alloc = __pool_alloc<Key>;
template<typename Key>
using pairing_heap = pairing_heap<Key, greater<Key>, pool_alloc<Key>>;
template<typename Key>
using indexed_set = tree<Key,null_type,less<Key>,rb_tree_tag,tree_order_statistics_node_update>;
{% endhighlight %}

[Back](../..)
