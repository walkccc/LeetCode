class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (root == nullptr)
      return 0;

    TreeNode* left = root;
    TreeNode* right = root;
    int heightL = 0;
    int heightR = 0;

    while (left != nullptr) {
      ++heightL;
      left = left->left;
    }

    while (right != nullptr) {
      ++heightR;
      right = right->right;
    }

    if (heightL == heightR)  // `root` is a complete tree.
      return pow(2, heightL) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
