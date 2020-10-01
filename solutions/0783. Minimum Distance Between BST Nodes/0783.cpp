class Solution {
 public:
  int minDiffInBST(TreeNode* root) {
    int ans = INT_MAX;
    int prev = -1;

    function<void(TreeNode*)> inorder = [&](TreeNode* root) {
      if (!root) return;

      inorder(root->left);
      if (prev >= 0)
        ans = min(ans, root->val - prev);
      prev = root->val;
      inorder(root->right);
    };

    inorder(root);

    return ans;
  }
};