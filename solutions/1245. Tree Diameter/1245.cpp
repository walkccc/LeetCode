class Solution {
 public:
  int treeDiameter(vector<vector<int>>& edges) {
    const int n = edges.size();
    int ans = 0;
    vector<vector<int>> tree(n + 1);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    maxDepth(tree, 0, -1, ans);
    return ans;
  }

 private:
  int maxDepth(const vector<vector<int>>& tree, int u, int parent, int& ans) {
    int maxDepth1 = 0;   // the maximum depth
    int maxDepth2 = -1;  // the second maximum depth

    for (const int v : tree[u]) {
      if (v == parent)
        continue;
      const int depth = maxDepth(tree, v, u, ans);
      if (depth > maxDepth1) {
        maxDepth2 = maxDepth1;
        maxDepth1 = depth;
      } else if (depth > maxDepth2) {
        maxDepth2 = depth;
      }
    }

    ans = max(ans, maxDepth1 + maxDepth2);
    return 1 + maxDepth1;
  }
};
