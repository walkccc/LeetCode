class Solution {
 public:
  bool isCompleteTree(TreeNode* root) {
    // calculate the # of nodes
    const int count = getCount(root);

    // make sure no index is > the # of nodes
    function<bool(TreeNode*, int)> helper = [&](TreeNode* root, int index) {
      if (!root) return true;
      if (index > count) return false;

      return helper(root->left, index * 2) &&
             helper(root->right, index * 2 + 1);
    };

    return helper(root, 1);
  }

 private:
  int getCount(TreeNode* root) {
    if (!root) return 0;
    return 1 + getCount(root->left) + getCount(root->right);
  }
};