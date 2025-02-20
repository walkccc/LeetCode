struct T {
  int mn;    // the minimum value in the subtree
  int mx;    // the maximum value in the subtree
  int size;  // the size of the subtree
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

    if (l.mx < root->val && root->val < r.mn)
      return {min(l.mn, root->val), max(r.mx, root->val), 1 + l.size + r.size};

    // Mark one as invalid, but still record the size of children.
    // Return (-INF, INF) because no node will be > INT or < -INF.
    return {INT_MIN, INT_MAX, max(l.size, r.size)};
  }
};
