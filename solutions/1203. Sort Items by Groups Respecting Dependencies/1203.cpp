class Solution {
 public:
  vector<int> sortItems(int n, int m, vector<int>& group,
                        vector<vector<int>>& beforeItems) {
    vector<vector<int>> graph(n + m);
    vector<int> inDegrees(n + m);

    // Build the graph by remapping the k-th group to k + n imaginary node.
    for (int i = 0; i < group.size(); ++i) {
      if (group[i] == -1)
        continue;
      graph[group[i] + n].push_back(i);
      ++inDegrees[i];
    }

    for (int i = 0; i < beforeItems.size(); ++i)
      for (const int b : beforeItems[i]) {
        const int u = group[b] == -1 ? b : group[b] + n;
        const int v = group[i] == -1 ? i : group[i] + n;
        if (u == v) {  // u and v are already in the same group.
          graph[b].push_back(i);
          ++inDegrees[i];
        } else {
          graph[u].push_back(v);
          ++inDegrees[v];
        }
      }

    // Perform topological sorting.
    vector<int> ans;

    for (int i = 0; i < n + m; ++i)
      if (inDegrees[i] == 0)  // inDegrees[i] == -1 means visited.
        dfs(graph, i, inDegrees, n, ans);

    return ans.size() == n ? ans : vector<int>();
  }

 private:
  void dfs(const vector<vector<int>>& graph, int u, vector<int>& inDegrees,
           int n, vector<int>& ans) {
    if (u < n)
      ans.push_back(u);

    inDegrees[u] = -1;  // Mark as visited.

    for (const int v : graph[u])
      if (--inDegrees[v] == 0)
        dfs(graph, v, inDegrees, n, ans);
  }
};
