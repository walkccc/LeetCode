class Solution {
 public:
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> ans;
    vector<int> path;

    function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int sum) {
      if (!root) return;
      if (root->val == sum && !root->left && !root->right) {
        path.push_back(root->val);
        ans.push_back(path);
        path.pop_back();
        return;
      }

      path.push_back(root->val);
      dfs(root->left, sum - root->val);
      dfs(root->right, sum - root->val);
      path.pop_back();
    };

    dfs(root, sum);

    return ans;
  }
};