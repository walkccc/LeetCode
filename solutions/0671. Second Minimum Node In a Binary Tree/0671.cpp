class Solution {
 public:
  int findSecondMinimumValue(TreeNode* root) {
    if (!root || !root->left) return -1;

    int l = root->left->val;
    int r = root->right->val;

    // check if left/right child's value == parent's value
    if (l == root->val) l = findSecondMinimumValue(root->left);
    if (r == root->val) r = findSecondMinimumValue(root->right);

    if (l > -1 && r > -1) return min(l, r);
    if (l > -1) return l;
    return r;
  }
};