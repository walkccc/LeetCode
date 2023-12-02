class Solution {
 public:
  vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    vector<int> ans;
    dfs(root, 0, voyage, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* root, int&& i, const vector<int>& voyage,
           vector<int>& ans) {
    if (root == nullptr)
      return;
    if (root->val != voyage[i++]) {
      ans.clear();
      ans.push_back(-1);
      return;
    }

    if (i < voyage.size() && root->left && root->left->val != voyage[i]) {
      // Flip the root.
      ans.push_back(root->val);
      dfs(root->right, move(i), voyage, ans);
      dfs(root->left, move(i), voyage, ans);
    } else {
      dfs(root->left, move(i), voyage, ans);
      dfs(root->right, move(i), voyage, ans);
    }
  }
};
