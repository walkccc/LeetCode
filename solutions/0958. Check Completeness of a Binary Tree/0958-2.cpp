class Solution {
 public:
  bool isCompleteTree(TreeNode* root) {
    const int count = getCount(root);
    return validIndex(root, 1, count);
  }

 private:
  // calculate the # of nodes
  int getCount(TreeNode* root) {
    if (!root)
      return 0;
    return 1 + getCount(root->left) + getCount(root->right);
  }

  // make sure no index is > the # of nodes
  bool validIndex(TreeNode* root, int index, int count) {
    if (!root)
      return true;
    if (index > count)
      return false;

    return validIndex(root->left, index * 2, count) &&
           validIndex(root->right, index * 2 + 1, count);
  }
};
