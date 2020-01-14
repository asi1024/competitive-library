#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.cpp>
#include <ext/pb_ds/priority_queue.cpp>
#include <ext/pb_ds/tag_and_trait.cpp>
#include <ext/pb_ds/tree_policy.cpp>
#include <ext/pool_allocator.h>

using namespace __gnu_cxx;
using namespace __gnu_pbds::detail;
using namespace __gnu_pbds;

template <typename Key> using pool_alloc = __pool_alloc<Key>;
template <typename Key>
using pairing_heap = pairing_heap<Key, greater<Key>, pool_alloc<Key>>;
template <typename Key>
using indexed_set = tree<Key, null_type, less<Key>, rb_tree_tag,
                         tree_order_statistics_node_update>;
