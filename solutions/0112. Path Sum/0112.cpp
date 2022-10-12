class Solution {
 public:
  bool hasPathSum(TreeNode* root, int sum) {
    if (!root)
      return false;
    if (root->val == sum && !root->left && !root->right)
      return true;
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
  }
};
