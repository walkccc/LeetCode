class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;

    dfs(root, "", ans);

    return ans;
  }

 private:
  void dfs(TreeNode* root, const string& path, vector<string>& ans) {
    if (!root)
      return;
    if (!root->left && !root->right) {
      ans.push_back(path + to_string(root->val));
      return;
    }

    dfs(root->left, path + to_string(root->val) + "->", ans);
    dfs(root->right, path + to_string(root->val) + "->", ans);
  }
};
