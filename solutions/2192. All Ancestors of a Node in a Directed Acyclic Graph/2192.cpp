class Solution {
 public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> ans(n);
    vector<vector<int>> graph(n);

    for (const auto& e : edges)
      graph[e[0]].push_back(e[1]);

    for (int i = 0; i < n; ++i)
      dfs(graph, i, i, vector<bool>(n), ans);

    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& graph, int u, int ancestor,
           vector<bool>&& seen, vector<vector<int>>& ans) {
    seen[u] = true;
    for (const int v : graph[u]) {
      if (seen[v])
        continue;
      ans[v].push_back(ancestor);
      dfs(graph, v, ancestor, move(seen), ans);
    }
  }
};
