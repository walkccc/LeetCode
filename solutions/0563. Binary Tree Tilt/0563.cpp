class Solution {
 public:
  int findTilt(TreeNode* root) {
    int ans = 0;

    function<int(TreeNode*)> sum = [&](TreeNode* root) {
      if (!root) return 0;

      const int l = sum(root->left);
      const int r = sum(root->right);
      ans += abs(l - r);

      return root->val + l + r;
    };

    sum(root);

    return ans;
  }
};