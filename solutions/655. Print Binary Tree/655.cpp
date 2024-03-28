class Solution {
 public:
  vector<vector<string>> printTree(TreeNode* root) {
    const int m = maxHeight(root);
    const int n = pow(2, m) - 1;
    vector<vector<string>> ans(m, vector<string>(n));
    dfs(root, 0, 0, ans[0].size() - 1, ans);
    return ans;
  }

 private:
  int maxHeight(TreeNode* root) {
    if (root == nullptr)
      return 0;
    return 1 + max(maxHeight(root->left), maxHeight(root->right));
  }

  void dfs(TreeNode* root, int row, int left, int right,
           vector<vector<string>>& ans) {
    if (root == nullptr)
      return;

    const int mid = (left + right) / 2;
    ans[row][mid] = to_string(root->val);
    dfs(root->left, row + 1, left, mid - 1, ans);
    dfs(root->right, row + 1, mid + 1, right, ans);
  }
};
