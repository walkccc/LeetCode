class Solution {
 public:
  int heightOfTree(TreeNode* root) {
    if (root == nullptr)
      return 0;
    // Is leaf node.
    if (root->left != nullptr && root->left->right == root)
      return 0;
    return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
  }
};
