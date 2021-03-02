class Solution {
 public:
  TreeNode* bstToGst(TreeNode* root) {
    int prefix = 0;

    function<void(TreeNode*)> reversedInorder = [&](TreeNode* root) {
      if (!root)
        return;

      reversedInorder(root->right);

      root->val += prefix;
      prefix = root->val;

      reversedInorder(root->left);
    };

    reversedInorder(root);

    return root;
  }
};
