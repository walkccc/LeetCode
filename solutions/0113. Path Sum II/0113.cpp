class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    dfs(root, sum, {}, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int sum, vector<int>&& path,
           vector<vector<int>>& ans) {
    if (!root)
      return;
    if (root->val == sum && !root->left && !root->right) {
      path.push_back(root->val);
      ans.push_back(path);
      path.pop_back();
      return;
    }

    path.push_back(root->val);
    dfs(root->left, sum - root->val, move(path), ans);
    dfs(root->right, sum - root->val, move(path), ans);
    path.pop_back();
  }
};
