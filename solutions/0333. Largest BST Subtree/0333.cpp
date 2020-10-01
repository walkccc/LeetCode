struct T {
  int min;   // min value in the subtree
  int max;   // max value in the subtree
  int size;  // total size of the subtree
};

class Solution {
 public:
  int largestBSTSubtree(TreeNode* root) {
    return helper(root).size;
  }

 private:
  T helper(TreeNode* root) {
    if (!root) return {INT_MAX, INT_MIN, 0};

    T l = helper(root->left);
    T r = helper(root->right);

    if (l.max < root->val && root->val < r.min)
      return {min(l.min, root->val), max(r.max, root->val),
              1 + l.size + r.size};

    // mark as invalid one, but still record the size of children
    // return (-INF, INF) because any node won't > INT and < -INF
    return {INT_MIN, INT_MAX, max(l.size, r.size)};
  }
};