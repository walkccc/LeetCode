class Solution {
 public:
  vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
    vector<int> ans(n);
    vector<vector<pair<int, bool>>> graph(n);
    vector<bool> seen(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].emplace_back(v, /*isForward=*/true);
      graph[v].emplace_back(u, /*isForward=*/false);
    }

    vector<int> mem(n, -1);
    ans[0] = minEdgeReversals(graph, 0, seen, mem);
    seen = vector<bool>(n);
    dfs(graph, 0, seen, ans);
    return ans;
  }

 private:
  // Returns the minimum number of edge reversals so node u can reach every
  // node in its subtree.
  int minEdgeReversals(const vector<vector<pair<int, bool>>>& graph, int u,
                       vector<bool>& seen, vector<int>& mem) {
    if (mem[u] != -1)
      return mem[u];
    int res = 0;
    seen[u] = true;
    for (const auto& [v, isForward] : graph[u]) {
      if (seen[v])
        continue;
      seen[v] = true;
      res += minEdgeReversals(graph, v, seen, mem) + (isForward ? 0 : 1);
    }
    return mem[u] = res;
  }

  void dfs(const vector<vector<pair<int, bool>>>& graph, int u,
           vector<bool>& seen, vector<int>& ans) {
    seen[u] = true;
    for (const auto& [v, isForward] : graph[u]) {
      if (seen[v])
        continue;
      seen[v] = true;
      ans[v] = ans[u] + (isForward ? 1 : -1);
      dfs(graph, v, seen, ans);
    }
  }
};
