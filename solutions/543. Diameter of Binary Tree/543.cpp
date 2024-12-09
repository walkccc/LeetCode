class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;
    maxDepth(root, ans);
    return ans;
  }

 private:
  int maxDepth(TreeNode* root, int& ans) {
    if (root == nullptr)
      return 0;

    const int l = maxDepth(root->left, ans);
    const int r = maxDepth(root->right, ans);
    ans = max(ans, l + r);
    return 1 + max(l, r);
  }
};
