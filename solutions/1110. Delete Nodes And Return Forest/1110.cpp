class Solution {
 public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> ans;
    dfs(root, {to_delete.begin(), to_delete.end()}, true, ans);
    return ans;
  }

 private:
  TreeNode* dfs(TreeNode*& root, const unordered_set<int>&& toDeleteSet,
                bool isRoot, vector<TreeNode*>& ans) {
    if (root == nullptr)
      return nullptr;

    const bool deleted = toDeleteSet.count(root->val);
    if (isRoot && !deleted)
      ans.push_back(root);

    // If root is deleted, both children have the possibility to be a new root
    root->left = dfs(root->left, move(toDeleteSet), deleted, ans);
    root->right = dfs(root->right, move(toDeleteSet), deleted, ans);
    return deleted ? nullptr : root;
  }
};
