struct T {
  TreeNode* lca;
  int depth;
};

class Solution {
 public:
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    return dfs(root).lca;
  }

 private:
  T dfs(TreeNode* root) {
    if (!root)
      return {nullptr, 0};

    T l = dfs(root->left);
    T r = dfs(root->right);
    if (l.depth > r.depth)
      return {l.lca, l.depth + 1};
    if (l.depth < r.depth)
      return {r.lca, r.depth + 1};
    return {root, l.depth + 1};
  }
};
