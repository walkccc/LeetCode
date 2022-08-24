class Solution {
 public:
  int reachableNodes(int n, vector<vector<int>>& edges,
                     vector<int>& restricted) {
    vector<vector<int>> graph(n);
    vector<bool> seen(n);

    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (const int r : restricted)
      seen[r] = true;

    return dfs(graph, 0, seen);
  }

 private:
  int dfs(const vector<vector<int>>& graph, int u, vector<bool>& seen) {
    if (seen[u])
      return 0;

    seen[u] = true;
    int ans = 1;

    for (const int v : graph[u])
      ans += dfs(graph, v, seen);

    return ans;
  }
};
