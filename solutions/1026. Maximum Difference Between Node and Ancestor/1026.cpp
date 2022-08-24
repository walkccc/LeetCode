class Solution {
 public:
  int maxAncestorDiff(TreeNode* root) {
    return maxAncestorDiff(root, root->val, root->val);
  }

 private:
  // return |max - min| of the tree w/ root
  int maxAncestorDiff(TreeNode* root, int mini, int maxi) {
    if (!root)
      return 0;

    mini = min(mini, root->val);
    maxi = max(maxi, root->val);
    const int l = maxAncestorDiff(root->left, mini, maxi);
    const int r = maxAncestorDiff(root->right, mini, maxi);
    return max({maxi - mini, l, r});
  }
};
