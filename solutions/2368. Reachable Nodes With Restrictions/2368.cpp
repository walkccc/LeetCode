class Solution {
 public:
  int reachableNodes(int n, vector<vector<int>>& edges,
                     vector<int>& restricted) {
    vector<vector<int>> tree(n);
    vector<bool> seen(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    for (const int r : restricted)
      seen[r] = true;

    return dfs(tree, 0, seen);
  }

 private:
  int dfs(const vector<vector<int>>& tree, int u, vector<bool>& seen) {
    if (seen[u])
      return 0;

    seen[u] = true;
    int ans = 1;

    for (const int v : tree[u])
      ans += dfs(tree, v, seen);

    return ans;
  }
};
