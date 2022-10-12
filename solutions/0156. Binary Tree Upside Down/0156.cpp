class Solution {
 public:
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    if (!root || !root->left)
      return root;

    TreeNode* newRoot = upsideDownBinaryTree(root->left);
    root->left->left = root->right;  // 2's left = 3 (root's right)
    root->left->right = root;        // 2's right = 1 (root)
    root->left = nullptr;
    root->right = nullptr;
    return newRoot;
  }
};
