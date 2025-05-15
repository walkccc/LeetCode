class Solution {
 public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n);

    for (const vector<int>& connection : connections) {
      const int u = connection[0];
      const int v = connection[1];
      graph[u].push_back(v);
      graph[v].push_back(-u);  // - := u -> v
    }

    return dfs(graph, 0, -1);
  }

 private:
  int dfs(const vector<vector<int>>& graph, int u, int prev) {
    int change = 0;

    for (const int v : graph[u]) {
      if (abs(v) == prev)
        continue;
      if (v > 0)
        ++change;
      change += dfs(graph, abs(v), u);
    }

    return change;
  }
};
