class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    int prefixSum = 0;

    function<void(TreeNode*)> reversedInorder = [&](TreeNode* root) {
      if (!root) return;

      reversedInorder(root->right);

      root->val += prefixSum;
      prefixSum = root->val;

      reversedInorder(root->left);
    };

    reversedInorder(root);

    return root;
  }
};