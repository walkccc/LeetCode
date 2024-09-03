class Solution {
 public:
  int findSecondMinimumValue(TreeNode* root) {
    if (root == nullptr)
      return -1;
    return findSecondMinimumValue(root, root->val);
  }

 private:
  int findSecondMinimumValue(TreeNode* root, int mn) {
    if (root == nullptr)
      return -1;
    if (root->val > mn)
      return root->val;

    const int leftMin = findSecondMinimumValue(root->left, mn);
    const int rightMin = findSecondMinimumValue(root->right, mn);

    if (leftMin == -1 || rightMin == -1)
      return max(leftMin, rightMin);
    return min(leftMin, rightMin);
  }
};
