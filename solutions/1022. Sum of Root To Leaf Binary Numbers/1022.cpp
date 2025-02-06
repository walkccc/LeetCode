class Solution {
 public:
  int sumRootToLeaf(TreeNode* root) {
    int ans = 0;
    dfs(root, 0, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int val, int& ans) {
    if (root == nullptr)
      return;
    val = val * 2 + root->val;
    if (root->left == nullptr && root->right == nullptr)
      ans += val;
    dfs(root->left, val, ans);
    dfs(root->right, val, ans);
  }
};
