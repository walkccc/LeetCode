class Solution {
 public:
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
                                         int source, int destination,
                                         int target) {
    constexpr int kMax = 2'000'000'000;
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      if (w == -1)
        continue;
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    int distToDestination = dijkstra(graph, source, destination);
    if (distToDestination < target)
      return {};
    if (distToDestination == target) {
      // Change the weights of negative edges to an impossible value.
      for (vector<int>& edge : edges)
        if (edge[2] == -1)
          edge[2] = kMax;
      return edges;
    }

    for (int i = 0; i < edges.size(); ++i) {
      const int u = edges[i][0];
      const int v = edges[i][1];
      int& w = edges[i][2];
      if (w != -1)
        continue;
      w = 1;
      graph[u].emplace_back(v, 1);
      graph[v].emplace_back(u, 1);
      distToDestination = dijkstra(graph, source, destination);
      if (distToDestination <= target) {
        w += target - distToDestination;
        // Change the weights of negative edges to an impossible value.
        for (int j = i + 1; j < edges.size(); ++j)
          if (edges[j][2] == -1)
            edges[j][2] = kMax;
        return edges;
      }
    }

    return {};
  }

 private:
  int dijkstra(const vector<vector<pair<int, int>>>& graph, int src, int dst) {
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

    return dist[dst];
  }
};
