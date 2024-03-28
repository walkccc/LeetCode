class FindElements {
 public:
  FindElements(TreeNode* root) {
    dfs(root, 0);
  }

  bool find(int target) {
    return vals.count(target);
  }

 private:
  unordered_set<int> vals;

  void dfs(TreeNode* root, int val) {
    if (root == nullptr)
      return;

    root->val = val;
    vals.insert(val);
    dfs(root->left, val * 2 + 1);
    dfs(root->right, val * 2 + 2);
  }
};
