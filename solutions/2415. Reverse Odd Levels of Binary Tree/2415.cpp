class Solution {
 public:
  TreeNode* reverseOddLevels(TreeNode* root) {
    dfs(root->left, root->right, true);
    return root;
  }

 private:
  void dfs(TreeNode* left, TreeNode* right, bool isOddLevel) {
    if (left == nullptr)
      return;
    if (isOddLevel)
      swap(left->val, right->val);
    dfs(left->left, right->right, !isOddLevel);
    dfs(left->right, right->left, !isOddLevel);
  }
};
