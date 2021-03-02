class Solution {
 public:
  vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    vector<int> ans;
    int i = 0;

    dfs(root, i, voyage, ans);

    return ans;
  }

 private:
  void dfs(TreeNode* root, int& i, const vector<int>& voyage,
           vector<int>& ans) {
    if (!root)
      return;
    if (root->val != voyage[i++]) {
      ans.clear();
      ans.push_back(-1);
      return;
    }

    if (i < voyage.size() && root->left && root->left->val != voyage[i]) {
      // flip root
      ans.push_back(root->val);
      dfs(root->right, i, voyage, ans);
      dfs(root->left, i, voyage, ans);
    } else {
      dfs(root->left, i, voyage, ans);
      dfs(root->right, i, voyage, ans);
    }
  }
};
