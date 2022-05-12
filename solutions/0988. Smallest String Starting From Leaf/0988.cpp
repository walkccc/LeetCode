class Solution {
 public:
  string smallestFromLeaf(TreeNode* root) {
    string ans;

    dfs(root, "", ans);

    return ans;
  }

 private:
  void dfs(TreeNode* root, string&& path, string& ans) {
    if (!root)
      return;

    path.push_back(root->val + 'a');

    if (!root->left && !root->right) {
      reverse(begin(path), end(path));
      if (ans == "" || ans > path)
        ans = path;
      reverse(begin(path), end(path));  // roll back
    }

    dfs(root->left, move(path), ans);
    dfs(root->right, move(path), ans);
    path.pop_back();
  }
};
