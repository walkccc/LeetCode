class T {
  public TreeNode lca;
  public int depth;

  public T(TreeNode lca, int depth) {
    this.lca = lca;
    this.depth = depth;
  }
};

class Solution {
  public TreeNode subtreeWithAllDeepest(TreeNode root) {
    return dfs(root).lca;
  }

  private T dfs(TreeNode root) {
    if (root == null)
      return new T(null, 0);

    T l = dfs(root.left);
    T r = dfs(root.right);
    if (l.depth > r.depth)
      return new T(l.lca, l.depth + 1);
    if (l.depth < r.depth)
      return new T(r.lca, r.depth + 1);
    return new T(root, l.depth + 1);
  }
}
