class Solution {
 public:
  vector<long long> minCost(int n, vector<vector<int>>& roads,
                            vector<int>& appleCost, int k) {
    vector<long long> ans;
    vector<vector<pair<int, long>>> graph(n);

    for (const vector<int>& road : roads) {
      const int u = road[0] - 1;
      const int v = road[1] - 1;
      const int w = road[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    for (int i = 0; i < n; ++i)
      ans.push_back(dijkstra(graph, i, appleCost, k));

    return ans;
  }

 private:
  long dijkstra(const vector<vector<pair<int, long>>>& graph, int src,
                const vector<int>& appleCost, int k) {
    long ans = LONG_MAX;
    vector<long> dist(graph.size(), LONG_MAX);

    dist[src] = 0;
    using P = pair<long, int>;  // (d, u)
    priority_queue<P, vector<P>, greater<>> minHeap;
    minHeap.emplace(dist[src], src);

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      if (d > dist[u])
        continue;
      ans = min(ans, appleCost[u] + (k + 1) * d);
      for (const auto& [v, w] : graph[u])
        if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.emplace(dist[v], v);
        }
    }

    return ans;
  }
};
