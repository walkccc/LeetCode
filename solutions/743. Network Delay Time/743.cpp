class Solution {
 public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& time : times) {
      const int u = time[0] - 1;
      const int v = time[1] - 1;
      const int w = time[2];
      graph[u].emplace_back(v, w);
    }

    return dijkstra(graph, k - 1);
  }

 private:
  int dijkstra(const vector<vector<pair<int, int>>>& graph, int src) {
    vector<int> dist(graph.size(), INT_MAX);
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

    const int maxDist = ranges::max(dist);
    return maxDist == INT_MAX ? -1 : maxDist;
  }
};
