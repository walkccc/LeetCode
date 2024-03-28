class Solution {
 public:
  int minCost(int maxTime, vector<vector<int>>& edges,
              vector<int>& passingFees) {
    const int n = passingFees.size();
    vector<vector<pair<int, int>>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      const int w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    return dijkstra(graph, 0, n - 1, maxTime, passingFees);
  }

 private:
  int dijkstra(const vector<vector<pair<int, int>>>& graph, int src, int dst,
               int maxTime, const vector<int>& passingFees) {
    // cost[i] := the minimum cost to reach the i-th city
    vector<int> cost(graph.size(), INT_MAX);
    // dist[i] := the minimum time to reach the i-th city
    vector<int> dist(graph.size(), maxTime + 1);
    using T = tuple<int, int, int>;  // (cost[u], dist[u], u)
    priority_queue<T, vector<T>, greater<>> minHeap;

    cost[src] = passingFees[src];
    dist[src] = 0;
    minHeap.emplace(cost[src], dist[src], src);

    while (!minHeap.empty()) {
      const auto [currCost, d, u] = minHeap.top();
      minHeap.pop();
      if (u == dst)
        return cost[dst];
      for (const auto& [v, w] : graph[u]) {
        if (d + w > maxTime)
          continue;
        // Go from u -> v.
        if (currCost + passingFees[v] < cost[v]) {
          cost[v] = currCost + passingFees[v];
          dist[v] = d + w;
          minHeap.emplace(cost[v], dist[v], v);
        } else if (d + w < dist[v]) {
          dist[v] = d + w;
          minHeap.emplace(currCost + passingFees[v], dist[v], v);
        }
      }
    }

    return -1;
  }
};
