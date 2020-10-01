class Solution {
 public:
  int diameterOfBinaryTree(TreeNode* root) {
    int ans = 0;

    // longest path from root to leaf
    function<int(TreeNode*)> maxDepth = [&](TreeNode* root) {
      if (!root) return 0;

      const int l = maxDepth(root->left);
      const int r = maxDepth(root->right);
      ans = max(ans, l + r);

      return max(l, r) + 1;
    };

    maxDepth(root);

    return ans;
  }
};