class Solution {
 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> ans;
    unordered_set<int> toDeleteSet{begin(to_delete), end(to_delete)};

    dfs(root, toDeleteSet, true, ans);

    return ans;
  }

 private:
  void dfs(TreeNode*& root, unordered_set<int>& toDeleteSet, bool isRoot,
           vector<TreeNode*>& ans) {
    if (!root)
      return;

    const bool deleted = toDeleteSet.count(root->val);

    if (!deleted && isRoot)
      ans.push_back(root);

    // if root is deleted, both children have the possibility to be a new root
    dfs(root->left, toDeleteSet, deleted, ans);
    dfs(root->right, toDeleteSet, deleted, ans);

    if (deleted)
      root = nullptr;
  }
};
