class Solution {
 public:
  // Similar to 2203. Minimum Weighted Subgraph With the Required Paths
  vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
    vector<bool> ans;
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    const vector<int> from0 = dijkstra(graph, 0);
    const vector<int> from1 = dijkstra(graph, n - 1);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      ans.push_back(from0[u] + w + from1[v] == from0[n - 1] ||
                    from0[v] + w + from1[u] == from0[n - 1]);
    }

    return ans;
  }

 private:
  static constexpr int kMax = 1'000'000'000;

  vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int src) {
    vector<int> dist(graph.size(), kMax);
    using P = pair<int, int>;  // (d, u)
    priority_queue<P, vector<P>, greater<>> minHeap;

    dist[src] = 0;
    minHeap.emplace(dist[src], src);

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      if (d > dist[u])
        continue;
      for (const auto& [v, w] : graph[u])
        if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.emplace(dist[v], v);
        }
    }

    return dist;
  }
};
