class Solution {
 public:
  int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                              vector<int>& values, int k) {
    int ans = 0;
    vector<vector<int>> graph(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs(graph, 0, /*prev=*/-1, values, k, ans);
    return ans;
  }

 private:
  long dfs(const vector<vector<int>>& graph, int u, int prev,
           const vector<int>& values, int k, int& ans) {
    long treeSum = values[u];

    for (const int v : graph[u])
      if (v != prev)
        treeSum += dfs(graph, v, u, values, k, ans);

    if (treeSum % k == 0)
      ++ans;
    return treeSum;
  }
};
