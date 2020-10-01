class Solution {
 public:
  int pathSum(TreeNode* root, int sum) {
    if (!root) return 0;
    return helper(root, sum) +
           pathSum(root->left, sum) +
           pathSum(root->right, sum);
  }

 private:
  int helper(TreeNode* root, int sum) {
    if (!root) return 0;
    return (sum == root->val) +
           helper(root->left, sum - root->val) +
           helper(root->right, sum - root->val);
  }
};