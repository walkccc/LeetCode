class Solution {
 public:
  TreeNode* upsideDownBinaryTree(TreeNode* root) {
    TreeNode* prevRoot = nullptr;
    TreeNode* prevRightChild = nullptr;

    while (root) {
      TreeNode* nextRoot = root->left;  // cache next root
      root->left = prevRightChild;
      prevRightChild = root->right;
      root->right = prevRoot;
      prevRoot = root;  // record previous root
      root = nextRoot;  // update root
    }

    return prevRoot;
  }
};
