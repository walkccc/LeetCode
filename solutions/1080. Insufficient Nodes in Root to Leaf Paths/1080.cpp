class Solution {
 public:
  TreeNode* sufficientSubset(TreeNode* root, int limit) {
    if (root == nullptr)
      return nullptr;
    if (root->left == nullptr && root->right == nullptr)
      return root->val < limit ? nullptr : root;
    root->left = sufficientSubset(root->left, limit - root->val);
    root->right = sufficientSubset(root->right, limit - root->val);
    return root->left == nullptr && root->right == nullptr ? nullptr : root;
  }
};
