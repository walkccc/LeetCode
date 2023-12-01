class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;
    if (root->left == nullptr)
      return minDepth(root->right) + 1;
    if (root->right == nullptr)
      return minDepth(root->left) + 1;
    return min(minDepth(root->left), minDepth(root->right)) + 1;
  }
};
