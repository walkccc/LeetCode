class Solution {
 public:
  TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
    TreeNode* ans = nullptr;
    int targetDepth = -1;
    dfs(root, u, 0, targetDepth, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, TreeNode* u, int depth, int& targetDepth,
           TreeNode*& ans) {
    if (root == nullptr)
      return;
    if (root == u) {
      targetDepth = depth;
      return;
    }
    if (depth == targetDepth && ans == nullptr) {
      ans = root;
      return;
    }
    dfs(root->left, u, depth + 1, targetDepth, ans);
    dfs(root->right, u, depth + 1, targetDepth, ans);
  }
};
