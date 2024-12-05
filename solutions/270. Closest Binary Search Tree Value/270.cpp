class Solution {
 public:
  int closestValue(TreeNode* root, double target) {
    // If target < root->val, search the left subtree.
    if (target < root->val && root->left) {
      const int left = closestValue(root->left, target);
      if (abs(left - target) <= abs(root->val - target))
        return left;
    }

    // If target > root->val, search the right subtree.
    if (target > root->val && root->right) {
      const int right = closestValue(root->right, target);
      if (abs(right - target) < abs(root->val - target))
        return right;
    }

    return root->val;
  }
};
