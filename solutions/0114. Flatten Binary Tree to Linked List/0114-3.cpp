class Solution {
 public:
  void flatten(TreeNode* root) {
    if (!root)
      return;

    while (root) {
      if (root->left) {
        // find the rightmost root
        TreeNode* rightmost = root->left;
        while (rightmost->right)
          rightmost = rightmost->right;
        // rewire the connections
        rightmost->right = root->right;
        root->right = root->left;
        root->left = nullptr;
      }
      // move on to the right side of the tree
      root = root->right;
    }
  }
};
