struct T {
  int min;   // Min value in the subtree
  int max;   // Max value in the subtree
  int size;  // Total size of the subtree
};

class Solution {
 public:
  int largestBSTSubtree(TreeNode* root) {
    return dfs(root).size;
  }

 private:
  T dfs(TreeNode* root) {
    if (root == nullptr)
      return {INT_MAX, INT_MIN, 0};

    T l = dfs(root->left);
    T r = dfs(root->right);

    if (l.max < root->val && root->val < r.min)
      return {min(l.min, root->val), max(r.max, root->val),
              1 + l.size + r.size};

    // Mark as invalid one, but still record the size of children
    // Returns (-INF, INF) because any node won't > INT and < -INF
    return {INT_MIN, INT_MAX, max(l.size, r.size)};
  }
};
