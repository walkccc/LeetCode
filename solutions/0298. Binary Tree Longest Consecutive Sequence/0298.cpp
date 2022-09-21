class Solution {
 public:
  int longestConsecutive(TreeNode* root) {
    if (!root)
      return 0;
    return dfs(root, root->val, 0, 0);
  }

 private:
  int dfs(TreeNode* root, int target, int length, int maxLength) {
    if (!root)
      return maxLength;
    if (root->val == target)
      maxLength = max(maxLength, ++length);
    else
      length = 1;
    return max(dfs(root->left, root->val + 1, length, maxLength),
               dfs(root->right, root->val + 1, length, maxLength));
  }
};
