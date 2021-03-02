class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    int ans = 0;
    int maxDepth = 0;

    dfs(root, 1, maxDepth, ans);

    return ans;
  }

 private:
  void dfs(TreeNode* root, int depth, int& maxDepth, int& ans) {
    if (!root)
      return;
    if (depth > maxDepth) {
      maxDepth = depth;
      ans = root->val;
    }

    dfs(root->left, depth + 1, maxDepth, ans);
    dfs(root->right, depth + 1, maxDepth, ans);
  }
};
