class Solution {
 public:
  int pathSum(vector<int>& nums) {
    int ans = 0;
    vector<vector<int>> tree(4, vector<int>(8, -1));

    for (const int num : nums) {
      const int d = num / 100 - 1;
      const int p = (num % 100) / 10 - 1;
      const int v = num % 10;
      tree[d][p] = v;
    }

    dfs(tree, 0, 0, 0, ans);
    return ans;
  }

 private:
  void dfs(const vector<vector<int>>& tree, int i, int j, int path, int& ans) {
    if (tree[i][j] == -1)
      return;
    if (i == 3 || max(tree[i + 1][j * 2], tree[i + 1][j * 2 + 1]) == -1) {
      ans += path + tree[i][j];
      return;
    }

    dfs(tree, i + 1, j * 2, path + tree[i][j], ans);
    dfs(tree, i + 1, j * 2 + 1, path + tree[i][j], ans);
  }
};
