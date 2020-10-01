class Solution {
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;

    function<void(TreeNode*, const string&)> dfs = [&](TreeNode* root,
                                                       const string& path) {
      if (!root) return;
      if (!root->left && !root->right) {
        ans.push_back(path + to_string(root->val));
        return;
      }

      dfs(root->left, path + to_string(root->val) + "->");
      dfs(root->right, path + to_string(root->val) + "->");
    };

    dfs(root, "");

    return ans;
  }
};