template <typename T>
struct SlideMin {
  deque<pair<int,T>> deq;
  int c, w;
  SlideMin(int w) : c(0), w(w) {;}
  T query(T d) {
    ++c;
    while (!deq.empty() && deq.front().first <= c - w) deq.pop_front();
    while (!deq.empty() && deq.back().second >= d) deq.pop_back();
    deq.push_back({c, d});
    return deq.front().second;
  }
};
