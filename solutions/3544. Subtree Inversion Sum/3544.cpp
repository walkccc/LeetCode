class Solution {
 public:
  long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums,
                                int k) {
    const int n = edges.size() + 1;
    vector<int> parent(n, -1);
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    vector<vector<vector<long>>> mem(
        n, vector<vector<long>>(k + 1, vector<long>(2, -1)));
    return dfs(graph, /*u=*/0, /*stepsSinceInversion=*/k,
               /*inverted=*/false, nums, k, parent, mem);
  }

 private:
  // Returns the maximum sum for subtree rooted at u, with `stepsSinceInversion`
  // steps of inversion and `inverted` is true if the subtree is inverted.
  long dfs(const vector<vector<int>>& graph, int u, int stepsSinceInversion,
           bool inverted, const vector<int>& nums, int k, vector<int>& parent,
           vector<vector<vector<long>>>& mem) {
    if (mem[u][stepsSinceInversion][inverted] != -1)
      return mem[u][stepsSinceInversion][inverted];
    long num = inverted ? -nums[u] : nums[u];
    long negNum = -num;
    for (const int v : graph[u]) {
      if (v == parent[u])
        continue;
      parent[v] = u;
      num += dfs(graph, v, min(k, stepsSinceInversion + 1), inverted, nums, k,
                 parent, mem);
      if (stepsSinceInversion == k)
        negNum += dfs(graph, v, /*stepsSinceInversion=*/1, !inverted, nums, k,
                      parent, mem);
    }
    return mem[u][stepsSinceInversion][inverted] =
               (stepsSinceInversion == k) ? max(num, negNum) : num;
  }
};
