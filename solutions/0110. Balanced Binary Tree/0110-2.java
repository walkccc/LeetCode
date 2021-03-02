class Solution {
  public boolean isBalanced(TreeNode root) {
    return maxDepth(root) != -1;
  }

  // return height of root if balanced; otherwise, return -1
  private int maxDepth(TreeNode root) {
    if (root == null)
      return 0;

    final int leftHeight = maxDepth(root.left);
    if (leftHeight == -1)
      return -1;
    final int rightHeight = maxDepth(root.right);
    if (rightHeight == -1)
      return -1;
    if (Math.abs(leftHeight - rightHeight) > 1)
      return -1;

    return 1 + Math.max(leftHeight, rightHeight);
  }
}
