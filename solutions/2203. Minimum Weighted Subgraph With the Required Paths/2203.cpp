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
  static constexpr long kMax = 1e10;

  vector<long> dijkstra(const vector<vector<pair<int, int>>>& graph, int src) {
    vector<long> dist(graph.size(), kMax);
    using P = pair<long, int>;
    priority_queue<P, vector<P>, greater<>> minHeap;  // (d, u)

    minHeap.emplace(0, src);

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      if (dist[u] != kMax)
        continue;
      dist[u] = d;
      for (const auto& [v, w] : graph[u])
        minHeap.emplace(d + w, v);
    }

    return dist;
  }
};
