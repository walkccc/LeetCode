class Solution {
 public:
  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    count(root, x);
    return max({leftCount, rightCount, n - leftCount - rightCount - 1}) > n / 2;
  }

 private:
  int leftCount;   // # of nodes of n's left
  int rightCount;  // # of nodes of n's right

  int count(TreeNode* root, int x) {
    if (!root)
      return 0;

    const int l = count(root->left, x);
    const int r = count(root->right, x);

    if (root->val == x) {
      leftCount = l;
      rightCount = r;
    }

    return 1 + l + r;
  }
};
