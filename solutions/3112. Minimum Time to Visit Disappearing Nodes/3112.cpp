class Solution {
 public:
  vector<int> minimumTime(int n, vector<vector<int>>& edges,
                          vector<int>& disappear) {
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    return dijkstra(graph, 0, disappear);
  }

 private:
  vector<int> dijkstra(const vector<vector<pair<int, int>>>& graph, int src,
                       const vector<int>& disappear) {
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
        if (d + w < disappear[v] && d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.push({dist[v], v});
        }
    }

    for (int& d : dist)
      if (d == INT_MAX)
        d = -1;

    return dist;
  }
};
