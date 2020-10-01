class Solution {
 public:
  vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;

    function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int depth) {
      if (!root) return;

      if (depth == ans.size())
        ans.push_back(root->val);
      dfs(root->right, depth + 1);
      dfs(root->left, depth + 1);
    };

    dfs(root, 0);

    return ans;
  }
};