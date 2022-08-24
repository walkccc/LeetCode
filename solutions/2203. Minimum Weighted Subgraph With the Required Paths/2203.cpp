class Solution {
 public:
  long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2,
                          int dest) {
    vector<vector<pair<int, int>>> graph1(n);
    vector<vector<pair<int, int>>> graph2(n);  // reversed(graph1)

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      const int w = e[2];
      graph1[u].emplace_back(v, w);
      graph2[v].emplace_back(u, w);
    }

    const vector<long> fromSrc1 = dijkstra(graph1, src1);
    const vector<long> fromSrc2 = dijkstra(graph1, src2);
    const vector<long> fromDest = dijkstra(graph2, dest);
    long ans = kMax;

    for (int i = 0; i < n; ++i) {
      if (fromSrc1[i] == kMax || fromSrc2[i] == kMax || fromDest[i] == kMax)
        continue;
      ans = min(ans, fromSrc1[i] + fromSrc2[i] + fromDest[i]);
    }

    return ans == kMax ? -1 : ans;
  }

 private:
  constexpr static long kMax = 1e10;

  vector<long> dijkstra(const vector<vector<pair<int, int>>>& graph, int src) {
    using P = pair<long, int>;
    priority_queue<P, vector<P>, greater<>> minHeap;  // (d, u)
    vector<long> dist(graph.size(), kMax);
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
