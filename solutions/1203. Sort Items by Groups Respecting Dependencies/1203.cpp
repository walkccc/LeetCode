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
        const int out = group[b] == -1 ? b : group[b] + n;
        const int in = group[i] == -1 ? i : group[i] + n;
        if (out == in) {  // already in the same group
          graph[b].push_back(i);
          ++inDegree[i];
        } else {
          graph[out].push_back(in);
          ++inDegree[in];
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
  void dfs(const vector<vector<int>>& graph, int out, vector<int>& inDegree,
           int n, vector<int>& ans) {
    if (out < n)
      ans.push_back(out);

    inDegree[out] = -1;  // mark as visited

    for (const int in : graph[out])
      if (--inDegree[in] == 0)
        dfs(graph, in, inDegree, n, ans);
  }
};
