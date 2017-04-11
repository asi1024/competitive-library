## skew_heap.cpp

```
template<typename T>
struct Heap {
  T val;
  Heap *l, *r;
  Heap(T v) : val(v), l(nullptr), r(nullptr) {}
};

template<typename T>
Heap<T> *meld(Heap<T> *a, Heap<T> *b) {
  if (!a) return b;
  if (!b) return a;
  if (a->val > b->val) swap(a, b);
  a->r = meld(a->r, b);
  swap(a->l, a->r);
  return a;
}

template<typename T>
Heap<T> *push(Heap<T> *h, T v) {
  Heap<T> *p = new Heap<T>(v);
  return meld(h, p);
}

template<typename T>
Heap<T> *pop(Heap<T> *h) {
  Heap<T> *res = meld(h->l, h->r);
  free(h);
  return res;
}
```

- [Back](../)
