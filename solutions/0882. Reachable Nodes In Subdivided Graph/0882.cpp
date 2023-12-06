class Solution {
 public:
  int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
    vector<vector<pair<int, int>>> graph(n);
    vector<int> dist(graph.size(), maxMoves + 1);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int cnt = edge[2];
      graph[u].emplace_back(v, cnt);
      graph[v].emplace_back(u, cnt);
    }

    const int reachableNodes = dijkstra(graph, 0, maxMoves, dist);
    int reachableSubnodes = 0;

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int cnt = edge[2];
      // the number of reachable nodes of `edge` from `u`
      const int a = dist[u] > maxMoves ? 0 : min(maxMoves - dist[u], cnt);
      // the number of reachable nodes of `edge` from `v`
      const int b = dist[v] > maxMoves ? 0 : min(maxMoves - dist[v], cnt);
      reachableSubnodes += min(a + b, cnt);
    }

    return reachableNodes + reachableSubnodes;
  }

 private:
  int dijkstra(const vector<vector<pair<int, int>>>& graph, int src,
               int maxMoves, vector<int>& dist) {
    using P = pair<int, int>;  // (d, u)
    priority_queue<P, vector<P>, greater<>> minHeap;

    dist[src] = 0;
    minHeap.emplace(dist[src], src);

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      // Already took `maxMoves` to reach `u`, so can't explore anymore.
      if (d >= maxMoves)
        break;
      for (const auto& [v, w] : graph[u])
        if (d + w + 1 < dist[v]) {
          dist[v] = d + w + 1;
          minHeap.emplace(dist[v], v);
        }
    }

    return ranges::count_if(dist, [&](int d) { return d <= maxMoves; });
  }
};
