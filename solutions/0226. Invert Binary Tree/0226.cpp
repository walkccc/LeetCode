class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root)
      return nullptr;

    TreeNode* const left = root->left;
    TreeNode* const right = root->right;
    root->left = invertTree(right);
    root->right = invertTree(left);
    return root;
  }
};
