class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    if (!root)
      return true;
    return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 &&
           isBalanced(root->left) &&
           isBalanced(root->right);
  }

 private:
  int maxDepth(TreeNode* root) {
    if (!root)
      return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
  }
};
