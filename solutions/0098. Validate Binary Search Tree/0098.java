class Solution {
  public boolean isValidBST(TreeNode root) {
    return dfs(root, null, null);
  }

  private boolean dfs(TreeNode root, TreeNode minNode, TreeNode maxNode) {
    if (root == null)
      return true;
    if (minNode != null && minNode.val >= root.val || maxNode != null && maxNode.val <= root.val)
      return false;

    return dfs(root.left, minNode, root) && dfs(root.right, root, maxNode);
  }
}