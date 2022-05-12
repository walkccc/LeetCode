class Solution {
 public:
  int minDiffInBST(TreeNode* root) {
    int ans = INT_MAX;

    inorder(root, ans);

    return ans;
  }

 private:
  int pred = -1;

  void inorder(TreeNode* root, int& ans) {
    if (!root)
      return;

    inorder(root->left, ans);
    if (pred >= 0)
      ans = min(ans, root->val - pred);
    pred = root->val;
    inorder(root->right, ans);
  }
};
