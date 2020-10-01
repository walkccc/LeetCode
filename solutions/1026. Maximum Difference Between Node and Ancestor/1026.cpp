class Solution {
 public:
  int maxAncestorDiff(TreeNode* root) {
    return dfs(root, root->val, root->val);
  }

 private:
  // return |max - min| of the tree w/ root
  int dfs(TreeNode* root, int mini, int maxi) {
    if (!root) return 0;

    mini = min(mini, root->val);
    maxi = max(maxi, root->val);
    const int leftMaxDiff = dfs(root->left, mini, maxi);
    const int rightMaxDiff = dfs(root->right, mini, maxi);

    return max({maxi - mini, leftMaxDiff, rightMaxDiff});
  }
};