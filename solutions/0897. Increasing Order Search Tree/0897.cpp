class Solution {
 public:
  TreeNode* increasingBST(TreeNode* root, TreeNode* tail = nullptr) {
    if (!root)
      return tail;

    TreeNode* ans = increasingBST(root->left, root);
    root->left = nullptr;
    root->right = increasingBST(root->right, tail);
    return ans;
  }
};
