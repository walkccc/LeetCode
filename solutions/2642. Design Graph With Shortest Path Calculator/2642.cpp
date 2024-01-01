class Graph {
 public:
  Graph(int n, vector<vector<int>>& edges) {
    graph.resize(n);
    for (const vector<int>& edge : edges)
      addEdge(edge);
  }

  void addEdge(vector<int> edge) {
    const int u = edge[0];
    const int v = edge[1];
    const int w = edge[2];
    graph[u].emplace_back(v, w);
  }

  int shortestPath(int node1, int node2) {
    vector<int> dist(graph.size(), INT_MAX);
    using P = pair<int, int>;  // (d, u)
    priority_queue<P, vector<P>, greater<>> minHeap;

    dist[node1] = 0;
    minHeap.emplace(dist[node1], node1);

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      if (u == node2)
        return d;
      for (const auto& [v, w] : graph[u])
        if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.emplace(dist[v], v);
        }
    }

    return -1;
  }

 private:
  vector<vector<pair<int, int>>> graph;
};
