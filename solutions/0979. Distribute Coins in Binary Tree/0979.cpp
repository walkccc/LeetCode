class Solution {
 public:
  int distributeCoins(TreeNode* root) {
    int ans = 0;

    dfs(root, ans);

    return ans;
  }

  // return how many coins I can give (positive) / take (negative)
 private:
  int dfs(TreeNode* root, int& ans) {
    if (!root)
      return 0;

    const int l = dfs(root->left, ans);
    const int r = dfs(root->right, ans);
    ans += abs(l) + abs(r);

    return (root->val - 1) + l + r;
  }
};
