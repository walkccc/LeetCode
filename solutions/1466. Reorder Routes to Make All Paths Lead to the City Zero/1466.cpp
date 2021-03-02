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
  int dfs(const vector<vector<int>>& graph, int node, int parent) {
    int change = 0;

    for (const int child : graph[node]) {
      if (abs(child) == parent)
        continue;
      if (child > 0)
        ++change;
      change += dfs(graph, abs(child), node);
    }

    return change;
  }
};
