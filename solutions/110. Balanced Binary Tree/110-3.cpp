class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    return maxDepth(root) != -1;
  }

 private:
  // Returns the height of root if root is balanced; otherwise, returns -1.
  int maxDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;

    const int left = maxDepth(root->left);
    if (left == -1)
      return -1;
    const int right = maxDepth(root->right);
    if (right == -1)
      return -1;
    if (abs(left - right) > 1)
      return -1;

    return 1 + max(left, right);
  }
};
