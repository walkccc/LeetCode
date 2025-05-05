class Solution {
  public int maxAncestorDiff(TreeNode root) {
    return maxAncestorDiff(root, root.val, root.val);
  }

  // Returns |the maximum - the minimum| of the tree.
  private int maxAncestorDiff(TreeNode root, int mn, int mx) {
    if (root == null)
      return 0;
    mn = Math.min(mn, root.val);
    mx = Math.max(mx, root.val);
    final int l = maxAncestorDiff(root.left, mn, mx);
    final int r = maxAncestorDiff(root.right, mn, mx);
    return Math.max(mx - mn, Math.max(l, r));
  }
}
