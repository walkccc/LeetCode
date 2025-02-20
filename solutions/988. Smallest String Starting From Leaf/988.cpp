class Solution {
 public:
  string smallestFromLeaf(TreeNode* root) {
    string ans;
    dfs(root, "", ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, string&& path, string& ans) {
    if (root == nullptr)
      return;

    path.push_back(root->val + 'a');

    if (root->left == nullptr && root->right == nullptr) {
      ranges::reverse(path);
      if (ans == "" || ans > path)
        ans = path;
      ranges::reverse(path);  // Roll back.
    }

    dfs(root->left, std::move(path), ans);
    dfs(root->right, std::move(path), ans);
    path.pop_back();
  }
};
