class Solution {
 public:
  vector<int> findSubtreeSizes(vector<int>& parent, string s) {
    const int n = parent.size();
    vector<int> ans(n);
    vector<int> newParent = parent;
    vector<vector<int>> tree(n);

    for (int i = 1; i < n; ++i) {
      const int closest = findClosestAncestor(i, parent, s);
      if (closest != -1)
        newParent[i] = closest;
    }

    for (int i = 1; i < n; ++i)
      tree[newParent[i]].push_back(i);

    dfs(tree, 0, ans);
    return ans;
  }

 private:
  // Returns the closest ancestor of node `u` that has the same value as `u`.
  int findClosestAncestor(int u, const vector<int>& parent, const string& s) {
    for (int curr = parent[u]; curr != -1; curr = parent[curr])
      if (s[curr] == s[u])
        return curr;
    return -1;
  }

  int dfs(const vector<vector<int>>& tree, int u, vector<int>& ans) {
    int sz = 1;
    for (const int v : tree[u])
      sz += dfs(tree, v, ans);
    return ans[u] = sz;
  }
};
