class Solution {
 public:
  long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2,
                          int dest) {
    vector<vector<pair<int, int>>> graph(n);
    vector<vector<pair<int, int>>> reversedGraph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
      reversedGraph[v].emplace_back(u, w);
    }

    const vector<long> fromSrc1 = dijkstra(graph, src1);
    const vector<long> fromSrc2 = dijkstra(graph, src2);
    const vector<long> fromDest = dijkstra(reversedGraph, dest);
    long ans = kMax;

    for (int i = 0; i < n; ++i) {
      if (fromSrc1[i] == kMax || fromSrc2[i] == kMax || fromDest[i] == kMax)
        continue;
      ans = min(ans, fromSrc1[i] + fromSrc2[i] + fromDest[i]);
    }

    return ans == kMax ? -1 : ans;
  }

 private:
  static constexpr long kMax = 10'000'000'000;

  vector<long> dijkstra(const vector<vector<pair<int, int>>>& graph, int src) {
    vector<long> dist(graph.size(), kMax);
    using P = pair<long, int>;  // (d, u)
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
