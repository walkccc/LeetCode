class Solution {
 public:
  vector<int> closestNode(int n, vector<vector<int>>& edges,
                          vector<vector<int>>& query) {
    vector<int> ans;
    vector<vector<int>> graph(n);
    vector<vector<int>> dist(n, vector<int>(n, -1));

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
      fillDist(graph, i, i, 0, dist);

    for (const auto& q : query) {
      const int start = q[0];
      const int end = q[1];
      const int node = q[2];
      ans.push_back(findClosest(graph, dist, start, end, node, start));
    }

    return ans;
  }

 private:
  void fillDist(const vector<vector<int>>& graph, int start, int u, int d,
                vector<vector<int>>& dist) {
    dist[start][u] = d;
    for (const int v : graph[u])
      if (dist[start][v] == -1)
        fillDist(graph, start, v, d + 1, dist);
  }

  int findClosest(const vector<vector<int>>& graph,
                  const vector<vector<int>>& dist, int u, int end, int node,
                  int ans) {
    for (const int v : graph[u])
      if (dist[v][end] < dist[u][end])
        return findClosest(graph, dist, v, end, node,
                           dist[ans][node] < dist[v][node] ? ans : v);
    return ans;
  }
};
