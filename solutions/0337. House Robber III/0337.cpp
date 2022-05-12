struct T {
  int robRoot;
  int notRobRoot;
};

class Solution {
 public:
  int rob(TreeNode* root) {
    const auto& [robRoot, notRobRoot] = robOrNotRob(root);
    return max(robRoot, notRobRoot);
  }

 private:
  T robOrNotRob(TreeNode* root) {
    if (!root)
      return {0, 0};
    const T l = robOrNotRob(root->left);
    const T r = robOrNotRob(root->right);
    return {root->val + l.notRobRoot + r.notRobRoot,
            max(l.robRoot, l.notRobRoot) + max(r.robRoot, r.notRobRoot)};
  }
};
