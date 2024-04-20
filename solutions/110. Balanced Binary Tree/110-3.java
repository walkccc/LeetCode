class Solution {
  public boolean isBalanced(TreeNode root) {
    return maxDepth(root) != -1;
  }

  // Returns the height of root if root is balanced; otherwise, returns -1.
  private int maxDepth(TreeNode root) {
    if (root == null)
      return 0;

    final int left = maxDepth(root.left);
    if (left == -1)
      return -1;
    final int right = maxDepth(root.right);
    if (right == -1)
      return -1;
    if (Math.abs(left - right) > 1)
      return -1;

    return 1 + Math.max(left, right);
  }
}
