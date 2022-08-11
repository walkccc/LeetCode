class Solution {
 public:
  int countUnivalSubtrees(TreeNode* root) {
    int ans = 0;
    isUnival(root, INT_MAX, ans);
    return ans;
  }

 private:
  bool isUnival(TreeNode* root, int val, int& ans) {
    if (!root)
      return true;

    if (isUnival(root->left, root->val, ans) &
        isUnival(root->right, root->val, ans)) {
      ++ans;
      return root->val == val;
    }

    return false;
  }
};
