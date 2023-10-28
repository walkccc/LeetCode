class Solution {
 public:
  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (root == nullptr)
      return nullptr;
    if (root->val <= p->val)
      return inorderSuccessor(root->right, p);

    TreeNode* left = inorderSuccessor(root->left, p);
    return left ? left : root;
  }
};
