class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    dfs(root, 0, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int depth, vector<int>& ans) {
    if (root == nullptr)
      return;

    if (depth == ans.size())
      ans.push_back(root->val);
    dfs(root->right, depth + 1, ans);
    dfs(root->left, depth + 1, ans);
  }
};
