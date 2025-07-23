class Solution {
 public:
  string tree2str(TreeNode* t) {
    return dfs(t);
  }

 private:
  string dfs(TreeNode* root) {
    if (root == nullptr)
      return "";

    const string& rootStr = to_string(root->val);
    if (root->right)
      return rootStr + "(" + dfs(root->left) + ")(" + dfs(root->right) + ")";
    if (root->left)
      return rootStr + "(" + dfs(root->left) + ")";
    return rootStr + "";
  }
};
