class Solution {
  public String getDirections(TreeNode root, int startValue, int destValue) {
    // Only this subtree matters.
    dfs(lca(root, startValue, destValue), startValue, destValue, new StringBuilder());
    return "U".repeat(pathToStart.length()) + pathToDest;
  }

  private String pathToStart = "";
  private String pathToDest = "";

  private TreeNode lca(TreeNode root, int p, int q) {
    if (root == null || root.val == p || root.val == q)
      return root;
    TreeNode left = lca(root.left, p, q);
    TreeNode right = lca(root.right, p, q);
    if (left != null && right != null)
      return root;
    return left == null ? right : left;
  }

  private void dfs(TreeNode root, int p, int q, StringBuilder path) {
    if (root == null)
      return;
    if (root.val == p)
      pathToStart = path.toString();
    if (root.val == q)
      pathToDest = path.toString();
    dfs(root.left, p, q, path.append('L'));
    path.deleteCharAt(path.length() - 1);
    dfs(root.right, p, q, path.append('R'));
    path.deleteCharAt(path.length() - 1);
  }
}
