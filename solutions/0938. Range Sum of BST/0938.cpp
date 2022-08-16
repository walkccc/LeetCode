class Solution {
 public:
  int rangeSumBST(TreeNode* root, int L, int R) {
    if (!root)
      return 0;
    if (root->val < L)
      return rangeSumBST(root->right, L, R);
    if (root->val > R)
      return rangeSumBST(root->left, L, R);
    return root->val + rangeSumBST(root->left, L, R) +
           rangeSumBST(root->right, L, R);
  }
};
