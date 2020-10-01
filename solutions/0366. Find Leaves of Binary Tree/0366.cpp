class Solution {
 public:
  vector<vector<int>> findLeaves(TreeNode* root) {
    vector<vector<int>> ans;

    // height of root
    function<int(TreeNode*)> height = [&](TreeNode* root) {
      if (!root) return 0;

      const int h = 1 + max(height(root->left), height(root->right));
      if (ans.size() == h - 1)  // meet leaf
        ans.push_back(vector<int>());
      ans[h - 1].push_back(root->val);

      return h;
    };

    height(root);

    return ans;
  }
};