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
      reverse(begin(path), end(path));
      if (ans == "" || ans > path)
        ans = path;
      reverse(begin(path), end(path));  // Roll back
    }

    dfs(root->left, move(path), ans);
    dfs(root->right, move(path), ans);
    path.pop_back();
  }
};
