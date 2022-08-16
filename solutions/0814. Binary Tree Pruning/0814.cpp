class Solution {
 public:
  TreeNode* pruneTree(TreeNode* root) {
    if (!root)
      return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if (!root->left && !root->right && !root->val)
      return nullptr;
    return root;
  }
};
