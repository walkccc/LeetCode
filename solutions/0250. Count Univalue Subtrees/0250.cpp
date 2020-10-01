class Solution {
 public:
  int countUnivalSubtrees(TreeNode* root) {
    int ans = 0;

    function<bool(TreeNode*, int)> isUnival = [&](TreeNode* root, int val) {
      if (!root) return true;

      if (isUnival(root->left, root->val) & isUnival(root->right, root->val)) {
        ++ans;
        return root->val == val;
      }

      return false;
    };

    isUnival(root, INT_MAX);

    return ans;
  }
};