## articulation_points.cpp

- [GitHub]({{ site.github.repository_url }}/blob/master/cpp/include/graph/articulation_points.cpp)

{% highlight cpp %}
struct Edge {
  int from, to;
  Edge(int s, int t) : from(s), to(t) {}
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph &g, int from, int to) {
  g[from].push_back(Edge(from, to));
  g[to].push_back(Edge(to, from));
}

class ArticulationPoints {
  const int n;
  const Graph g;
  set<int> art;
  vector<vector<Edge>> connect;
  vector<Edge> st;
  vector<int> order, low;
  int cnt;
  void dfs(int from, int parent) {
    low[from] = order[from] = cnt++;
    for (Edge e : g[from]) {
      const int to = e.to;
      if (to != parent && order[to] < order[from]) st.push_back(e);
      if (order[to] == -1) {
        dfs(to, from);
        low[from] = min(low[from], low[to]);
        if ((order[from] == 0 && order[to] != 1) ||
            (order[from] != 0 && low[to] >= order[from])) art.insert(from);
        if (low[to] >= order[from]) {
          connect.push_back(vector<Edge>());
          for (;;) {
            Edge edge = st.back();
            st.pop_back();
            connect.back().push_back(edge);
            if (edge.from == from && edge.to == to) break;
          }
        }
      }
      else {
        low[from] = min(low[from], order[to]);
      }
    }
  }
public:
  ArticulationPoints(const Graph &g) :
    n(g.size()), g(g), art(), connect(), st(), order(n, -1), low(n, -1) {
    for (int i = 0; i < n; i++) {
      if (order[i] != -1) continue;
      cnt = 0;
      dfs(i, i);
    }
  }
  set<int> vertices() const { return art; }
  vector<vector<Edge>> edges() const { return connect; }
};
{% endhighlight %}

- [Back](../../..)
