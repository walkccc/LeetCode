class Solution {
 public:
  int longestUnivaluePath(TreeNode* root) {
    int ans = 0;
    longestUnivaluePathDownFrom(root, ans);
    return ans;
  }

 private:
  int longestUnivaluePathDownFrom(TreeNode* root, int& ans) {
    if (!root)
      return 0;

    const int l = longestUnivaluePathDownFrom(root->left, ans);
    const int r = longestUnivaluePathDownFrom(root->right, ans);
    const int arrowLeft =
        root->left && root->left->val == root->val ? l + 1 : 0;
    const int arrowRight =
        root->right && root->right->val == root->val ? r + 1 : 0;
    ans = max(ans, arrowLeft + arrowRight);
    return max(arrowLeft, arrowRight);
  }
};
