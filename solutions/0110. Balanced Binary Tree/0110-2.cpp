class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    return maxDepth(root) != -1;
  }

 private:
  // return height of root if balanced; otherwise, return -1
  int maxDepth(TreeNode* root) {
    if (!root)
      return 0;

    const int leftHeight = maxDepth(root->left);
    if (leftHeight == -1)
      return -1;
    const int rightHeight = maxDepth(root->right);
    if (rightHeight == -1)
      return -1;
    if (abs(leftHeight - rightHeight) > 1)
      return -1;

    return 1 + max(leftHeight, rightHeight);
  }
};
