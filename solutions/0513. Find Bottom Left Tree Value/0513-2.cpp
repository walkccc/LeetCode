class Solution {
 public:
  int findBottomLeftValue(TreeNode* root) {
    int ans = 0;
    dfs(root, 1, 0, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int depth, int&& maxDepth, int& ans) {
    if (root == nullptr)
      return;
    if (depth > maxDepth) {
      maxDepth = depth;
      ans = root->val;
    }

    dfs(root->left, depth + 1, move(maxDepth), ans);
    dfs(root->right, depth + 1, move(maxDepth), ans);
  }
};
