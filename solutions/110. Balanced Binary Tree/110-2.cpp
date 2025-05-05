class Solution {
 public:
  bool isBalanced(TreeNode* root) {
    bool ans = true;
    maxDepth(root, ans);
    return ans;
  }

  // Returns the height of root and sets ans to false if root unbalanced.
  int maxDepth(TreeNode* root, bool& ans) {
    if (root == nullptr || !ans)
      return 0;
    const int left = maxDepth(root->left, ans);
    const int right = maxDepth(root->right, ans);
    if (abs(left - right) > 1)
      ans = false;
    return max(left, right) + 1;
  }
};
