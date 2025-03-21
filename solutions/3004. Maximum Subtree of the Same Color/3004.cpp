class Solution {
 public:
  int maximumSubtreeSize(vector<vector<int>>& edges, vector<int>& colors) {
    int ans = 1;
    vector<vector<int>> tree(colors.size());

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
    }

    dfs(tree, 0, colors, ans);
    return ans;
  }

 private:
  // Returns the size of subtree of u if every node in the subtree has the same
  // color. Otherwise, returns -1.
  int dfs(const vector<vector<int>>& tree, int u, const vector<int>& colors,
          int& ans) {
    int res = 1;
    for (const int v : tree[u]) {
      if (colors[v] != colors[u])
        res = -1;
      // If any node in the subtree of v has a different color, the result of
      // the subtree of u will be -1 as well.
      const int subtreeSize = dfs(tree, v, colors, ans);
      if (subtreeSize == -1)
        res = -1;
      else if (res != -1)
        res += subtreeSize;
    }
    ans = max(ans, res);
    return res;
  }
};
