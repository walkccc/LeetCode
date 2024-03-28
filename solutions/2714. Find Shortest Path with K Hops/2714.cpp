class Solution {
 public:
  // Similar to 787. Cheapest Flights Within K Stops
  int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int d,
                           int k) {
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    return dijkstra(graph, s, d, k);
  }

 private:
  int dijkstra(const vector<vector<pair<int, int>>>& graph, int src, int dst,
               int k) {
    vector<vector<int>> dist(graph.size(), vector<int>(k + 1, INT_MAX));
    using T = tuple<int, int, int>;  // (d, u, hops)
    priority_queue<T, vector<T>, greater<>> minHeap;

    dist[src][k] = 0;
    minHeap.emplace(dist[src][k], src, k);

    while (!minHeap.empty()) {
      const auto [d, u, hops] = minHeap.top();
      minHeap.pop();
      if (u == dst)
        return d;
      for (const auto& [v, w] : graph[u]) {
        // Go from u -> v with w cost.
        if (d + w < dist[v][hops]) {
          dist[v][hops] = d + w;
          minHeap.emplace(dist[v][hops], v, hops);
        }
        // Hop from u -> v with 0 cost.
        if (hops > 0 && d < dist[v][hops - 1]) {
          dist[v][hops - 1] = d;
          minHeap.emplace(dist[v][hops - 1], v, hops - 1);
        }
      }
    }

    throw;
  }
};
