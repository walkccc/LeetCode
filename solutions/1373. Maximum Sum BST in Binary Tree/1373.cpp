struct T {
  bool isBST = false;
  int mx;
  int mn;
  int sum;
};

class Solution {
 public:
  int maxSumBST(TreeNode* root) {
    int ans = 0;
    traverse(root, ans);
    return ans;
  }

 private:
  T traverse(TreeNode* root, int& ans) {
    if (root == nullptr)
      return T(true, INT_MIN, INT_MAX, 0);

    const T left = traverse(root->left, ans);
    const T right = traverse(root->right, ans);

    if (!left.isBST || !right.isBST)
      return T();
    if (root->val <= left.mx || root->val >= right.mn)
      return T();

    // The `root` is a valid BST.
    const int sum = root->val + left.sum + right.sum;
    ans = max(ans, sum);
    return T(true, max(root->val, right.mx), min(root->val, left.mn), sum);
  }
};
