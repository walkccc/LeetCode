class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int ans = INT_MIN;

    maxPathSumDownFrom(root, ans);

    return ans;
  }

 private:
  int maxPathSumDownFrom(TreeNode* root, int& ans) {
    if (!root) return 0;

    const int l = max(0, maxPathSumDownFrom(root->left, ans));
    const int r = max(0, maxPathSumDownFrom(root->right, ans));
    ans = max(ans, root->val + l + r);

    return root->val + max(l, r);
  }
};