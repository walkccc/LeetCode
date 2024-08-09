class Solution {
 public:
  int countRestrictedPaths(int n, vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0] - 1;
      const int v = edge[1] - 1;
      const int w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    return dijkstra(graph, 0, n - 1);
  }

 private:
  int dijkstra(const vector<vector<pair<int, int>>>& graph, int src, int dst) {
    constexpr int kMod = 1'000'000'007;
    // ways[i] := the number of restricted path from i to n
    vector<long> ways(graph.size());
    // dist[i] := the distance to the last node of i
    vector<long> dist(graph.size(), LONG_MAX);
    using P = pair<long, int>;  // (d, u)
    priority_queue<P, vector<P>, greater<>> minHeap;

    dist[dst] = 0;
    ways[dst] = 1;
    minHeap.emplace(dist[dst], dst);

    while (!minHeap.empty()) {
      const auto [d, u] = minHeap.top();
      minHeap.pop();
      if (d > dist[u])
        continue;
      for (const auto& [v, w] : graph[u]) {
        if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.emplace(dist[v], v);
        }
        if (dist[v] < dist[u]) {
          ways[u] += ways[v];
          ways[u] %= kMod;
        }
      }
    }

    return ways[src];
  }
};
