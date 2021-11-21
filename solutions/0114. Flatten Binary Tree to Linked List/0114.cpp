class Solution {
 public:
  void flatten(TreeNode* root) {
    flattendTail(root);
  }

 private:
  // return the tail of root after root is flattend
  TreeNode* flattendTail(TreeNode* root) {
    if (!root)
      return nullptr;
    if (!root->left && !root->right)
      return root;

    TreeNode* leftTail = flattendTail(root->left);
    TreeNode* rightTail = flattendTail(root->right);

    if (leftTail) {
      leftTail->right = root->right;
      root->right = root->left;
      root->left = nullptr;
    }

    return rightTail ? rightTail : leftTail;
  }
};
