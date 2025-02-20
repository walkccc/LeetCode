class Solution {
 public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<int> ans(n);
    vector<vector<int>> tree(n);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      tree[u].push_back(v);
      tree[v].push_back(u);
    }

    dfs(tree, 0, -1, labels, ans);
    return ans;
  }

 private:
  vector<int> dfs(const vector<vector<int>>& tree, int u, int prev,
                  const string& labels, vector<int>& ans) {
    // count[i] := the number of letters down from ('a' + i)
    vector<int> count(26);

    for (const int v : tree[u]) {
      if (v == prev)
        continue;
      vector<int> childCount = dfs(tree, v, u, labels, ans);
      for (int i = 0; i < 26; ++i)
        count[i] += childCount[i];
    }

    ans[u] = ++count[labels[u] - 'a'];  // the u itself
    return count;
  }
};
