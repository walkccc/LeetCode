struct T {
  int inc;  // length of longest incrementing branch
  int dec;  // length of longest decrementing branch
};

class Solution {
 public:
  int longestConsecutive(TreeNode* root) {
    int ans = 0;
    longestPath(root, ans);
    return ans;
  }

 private:
  // return (longest increment, longest decrement)
  T longestPath(TreeNode* root, int& ans) {
    if (!root)
      return {0, 0};

    int inc = 1;
    int dec = 1;

    if (root->left) {
      T l = longestPath(root->left, ans);
      if (root->val + 1 == root->left->val)
        inc = l.inc + 1;
      else if (root->val - 1 == root->left->val)
        dec = l.dec + 1;
    }

    if (root->right) {
      T r = longestPath(root->right, ans);
      if (root->val + 1 == root->right->val)
        inc = max(inc, r.inc + 1);
      else if (root->val - 1 == root->right->val)
        dec = max(dec, r.dec + 1);
    }

    ans = max(ans, inc + dec - 1);
    return {inc, dec};
  }
};
