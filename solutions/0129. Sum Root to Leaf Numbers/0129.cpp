class Solution {
 public:
  int sumNumbers(TreeNode* root) {
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int path, int& ans) {
    if (!root)
      return;
    if (!root->left && !root->right) {
      ans += path * 10 + root->val;
      return;
    }

    dfs(root->left, path * 10 + root->val, ans);
    dfs(root->right, path * 10 + root->val, ans);
  }
};
