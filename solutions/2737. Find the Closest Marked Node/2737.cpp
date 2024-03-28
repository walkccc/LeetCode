class Solution {
 public:
  int minimumDistance(int n, vector<vector<int>>& edges, int s,
                      vector<int>& marked) {
    int ans = INT_MAX;
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
    }

    const vector<int> dist = dijkstra(graph, s);

    for (const int u : marked)
      ans = min(ans, dist[u]);

    return ans == INT_MAX ? -1 : ans;
  }

 private:
  vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int src) {
    vector<int> dist(graph.size(), INT_MAX);
    using P = pair<int, int>;  // (d, u)
    priority_queue<P, vector<P>, greater<>> minHeap;

    dist[src] = 0;
    minHeap.emplace(dist[src], src);

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      for (const auto& [v, w] : graph[u])
        if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.emplace(dist[v], v);
        }
    }

    return dist;
  }
};
