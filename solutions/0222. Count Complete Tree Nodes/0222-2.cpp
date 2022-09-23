class Solution {
 public:
  int countNodes(TreeNode* root) {
    if (!root)
      return 0;

    TreeNode* l = root;
    TreeNode* r = root;
    int heightL = 0;
    int heightR = 0;

    while (l) {
      ++heightL;
      l = l->left;
    }

    while (r) {
      ++heightR;
      r = r->right;
    }

    if (heightL == heightR)  // root is a complete tree
      return pow(2, heightL) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
