class Solution {
 public:
  int findShortestCycle(int n, vector<vector<int>>& edges) {
    int ans = kInf;
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 0; i < n; ++i)
      ans = min(ans, bfs(graph, i));

    return ans == kInf ? -1 : ans;
  }

 private:
  static constexpr int kInf = 1001;

  // Returns the length of the minimum cycle by starting BFS from node `i`.
  // Returns `kInf` if there's no cycle.
  int bfs(const vector<vector<int>>& graph, int i) {
    vector<int> dist(graph.size(), kInf);
    queue<int> q{{i}};
    dist[i] = 0;
    while (!q.empty()) {
      const int u = q.front();
      q.pop();
      for (const int v : graph[u]) {
        if (dist[v] == kInf) {
          dist[v] = dist[u] + 1;
          q.push(v);
        } else if (dist[v] + 1 != dist[u]) {  // v is not a parent u.
          return dist[v] + dist[u] + 1;
        }
      }
    }
    return kInf;
  }
};
