class Solution {
  public int maxAncestorDiff(TreeNode root) {
    return maxAncestorDiff(root, root.val, root.val);
  }

  // return |max - min| of the tree w/ root
  private int maxAncestorDiff(TreeNode root, int mini, int maxi) {
    if (root == null)
      return 0;

    mini = Math.min(mini, root.val);
    maxi = Math.max(maxi, root.val);
    final int l = maxAncestorDiff(root.left, mini, maxi);
    final int r = maxAncestorDiff(root.right, mini, maxi);

    return Math.max(maxi - mini, Math.max(l, r));
  }
}
