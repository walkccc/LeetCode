class Solution {
 public:
  int pseudoPalindromicPaths(TreeNode* root) {
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int path, int& ans) {
    if (root == nullptr)
      return;
    if (root->left == nullptr && root->right == nullptr) {
      path ^= 1 << root->val;
      if ((path & (path - 1)) == 0)
        ++ans;
      return;
    }

    dfs(root->left, path ^ 1 << root->val, ans);
    dfs(root->right, path ^ 1 << root->val, ans);
  }
};
