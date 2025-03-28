class Solution {
 public:
  vector<int> getLonelyNodes(TreeNode* root) {
    vector<int> ans;

    dfs(root, false, ans);

    return ans;
  }

 private:
  void dfs(TreeNode* root, bool isLonely, vector<int>& ans) {
    if (root == nullptr)
      return;
    if (isLonely)
      ans.push_back(root->val);

    dfs(root->left, root->right == nullptr, ans);
    dfs(root->right, root->left == nullptr, ans);
  }
};
