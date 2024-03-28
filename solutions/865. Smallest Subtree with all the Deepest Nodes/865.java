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
    if (left.depth > right.depth)
      return new T(left.lca, left.depth + 1);
    if (left.depth < right.depth)
      return new T(right.lca, right.depth + 1);
    return new T(root, left.depth + 1);
  }
}
