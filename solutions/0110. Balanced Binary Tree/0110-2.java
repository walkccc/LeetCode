class Solution {
  public boolean isBalanced(TreeNode root) {
    maxDepth(root);
    return ans;
  }

  private boolean ans = true;

  // Returns the height of root and sets ans to false if root unbalanced.
  public int maxDepth(TreeNode root) {
    if (root == null || !ans)
      return 0;
    final int left = maxDepth(root.left);
    final int right = maxDepth(root.right);
    if (Math.abs(left - right) > 1)
      ans = false;
    return Math.max(left, right) + 1;
  }
}
