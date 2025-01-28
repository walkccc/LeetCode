class Solution {
 public:
  int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& road : roads) {
      const int u = road[0];
      const int v = road[1];
      const int w = road[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    return dijkstra(graph, 0, n - 1);
  }

 private:
  // Similar to 1786. Number of Restricted Paths From First to Last Node
  int dijkstra(const vector<vector<pair<int, int>>>& graph, int src, int dst) {
    constexpr int kMod = 1'000'000'007;
    vector<long> ways(graph.size());
    vector<long> dist(graph.size(), LONG_MAX);

    ways[src] = 1;
    dist[src] = 0;
    using P = pair<long, int>;  // (d, u)
    priority_queue<P, vector<P>, greater<>> minHeap;
    minHeap.emplace(dist[src], src);

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      if (d > dist[u])
        continue;
      for (const auto& [v, w] : graph[u])
        if (d + w < dist[v]) {
          dist[v] = d + w;
          ways[v] = ways[u];
          minHeap.emplace(dist[v], v);
        } else if (d + w == dist[v]) {
          ways[v] += ways[u];
          ways[v] %= kMod;
        }
    }

    return ways[dst];
  }
};
