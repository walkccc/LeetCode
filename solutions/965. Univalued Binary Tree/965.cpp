class Solution {
 public:
  bool isUnivalTree(TreeNode* root) {
    if (root == nullptr)
      return true;
    if (root->left != nullptr && root->left->val != root->val)
      return false;
    if (root->right != nullptr && root->right->val != root->val)
      return false;
    return isUnivalTree(root->left) && isUnivalTree(root->right);
  }
};
