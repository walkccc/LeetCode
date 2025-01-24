class Solution {
 public:
  int maxAncestorDiff(TreeNode* root) {
    return maxAncestorDiff(root, root->val, root->val);
  }

 private:
  // Returns |the maximum - the minimum| of the tree.
  int maxAncestorDiff(TreeNode* root, int mn, int mx) {
    if (root == nullptr)
      return 0;
    mn = min(mn, root->val);
    mx = max(mx, root->val);
    const int l = maxAncestorDiff(root->left, mn, mx);
    const int r = maxAncestorDiff(root->right, mn, mx);
    return max({mx - mn, l, r});
  }
};
