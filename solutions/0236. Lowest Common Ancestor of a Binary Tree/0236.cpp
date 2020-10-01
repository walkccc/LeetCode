class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;

    TreeNode* const left = lowestCommonAncestor(root->left, p, q);
    TreeNode* const right = lowestCommonAncestor(root->right, p, q);

    if (!left) return right;
    if (!right) return left;
    return root;  // both left and right are not nullptr
  }
};