class Solution {
  public int goodNodes(TreeNode root) {
    return goodNodes(root, Integer.MIN_VALUE);
  }

  private int goodNodes(TreeNode root, int mx) {
    if (root == null)
      return 0;

    final int newMax = Math.max(mx, root.val);
    return (root.val >= mx ? 1 : 0) + goodNodes(root.left, newMax) + goodNodes(root.right, newMax);
  }
}
