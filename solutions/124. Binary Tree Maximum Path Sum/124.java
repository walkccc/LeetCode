class Solution {
  public int maxPathSum(TreeNode root) {
    maxPathSumDownFrom(root);
    return ans;
  }

  private int ans = Integer.MIN_VALUE;

  // Returns the maximum path sum starting from the current root, where
  // root.val is always included.
  private int maxPathSumDownFrom(TreeNode root) {
    if (root == null)
      return 0;

    final int l = Math.max(maxPathSumDownFrom(root.left), 0);
    final int r = Math.max(maxPathSumDownFrom(root.right), 0);
    ans = Math.max(ans, root.val + l + r);
    return root.val + Math.max(l, r);
  }
}
