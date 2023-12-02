class Solution {
 public:
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                          TreeNode* target) {
    TreeNode* ans = nullptr;
    dfs(original, cloned, target, ans);
    return ans;
  }

 private:
  void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target,
           TreeNode*& ans) {
    if (ans != nullptr)
      return;
    if (original == nullptr)
      return;
    if (original == target) {
      ans = cloned;
      return;
    }
    dfs(original->left, cloned->left, target, ans);
    dfs(original->right, cloned->right, target, ans);
  }
};
