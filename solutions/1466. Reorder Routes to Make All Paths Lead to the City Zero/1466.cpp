class Solution {
 public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n);

    for (const auto& conn : connections) {
      graph[conn[0]].push_back(conn[1]);
      graph[conn[1]].push_back(-conn[0]);  // - := conn[0] -> conn[1]
    }

    return dfs(graph, 0, -1);
  }

 private:
  int dfs(const vector<vector<int>>& graph, int u, int parent) {
    int change = 0;

    for (const int v : graph[u]) {
      if (abs(v) == parent)
        continue;
      if (v > 0)
        ++change;
      change += dfs(graph, abs(v), u);
    }

    return change;
  }
};
