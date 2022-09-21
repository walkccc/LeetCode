class Solution {
 public:
  vector<int> sortItems(int n, int m, vector<int>& group,
                        vector<vector<int>>& beforeItems) {
    vector<vector<int>> graph(n + m);
    vector<int> inDegree(n + m);

    // build graph by remapping k-th group to k + n imaginary node
    for (int i = 0; i < group.size(); ++i) {
      if (group[i] == -1)
        continue;
      graph[group[i] + n].push_back(i);
      ++inDegree[i];
    }

    for (int i = 0; i < beforeItems.size(); ++i)
      for (const int b : beforeItems[i]) {
        const int u = group[b] == -1 ? b : group[b] + n;
        const int v = group[i] == -1 ? i : group[i] + n;
        if (u == v) {  // already in the same group
          graph[b].push_back(i);
          ++inDegree[i];
        } else {
          graph[u].push_back(v);
          ++inDegree[v];
        }
      }

    // topology
    vector<int> ans;

    for (int i = 0; i < n + m; ++i)
      if (inDegree[i] == 0)  // inDegree[i] == -1 means visited
        dfs(graph, i, inDegree, n, ans);

    return ans.size() == n ? ans : vector<int>();
  }

 private:
  void dfs(const vector<vector<int>>& graph, int u, vector<int>& inDegree,
           int n, vector<int>& ans) {
    if (u < n)
      ans.push_back(u);

    inDegree[u] = -1;  // mark as visited

    for (const int v : graph[u])
      if (--inDegree[v] == 0)
        dfs(graph, v, inDegree, n, ans);
  }
};
