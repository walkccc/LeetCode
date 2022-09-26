class Solution {
 public:
  TreeNode* convertBST(TreeNode* root) {
    int prefix = 0;
    reversedInorder(root, prefix);
    return root;
  }

 private:
  void reversedInorder(TreeNode* root, int& prefix) {
    if (!root)
      return;

    reversedInorder(root->right, prefix);
    prefix += root->val;
    root->val = prefix;
    reversedInorder(root->left, prefix);
  }
};
