class Solution {
  public int longestUnivaluePath(TreeNode root) {
    longestUnivaluePathDownFrom(root);
    return ans;
  }

  private int ans = 0;

  private int longestUnivaluePathDownFrom(TreeNode root) {
    if (root == null)
      return 0;

    final int l = longestUnivaluePathDownFrom(root.left);
    final int r = longestUnivaluePathDownFrom(root.right);
    final int arrowLeft = root.left != null && root.left.val == root.val ? l + 1 : 0;
    final int arrowRight = root.right != null && root.right.val == root.val ? r + 1 : 0;
    ans = Math.max(ans, arrowLeft + arrowRight);
    return Math.max(arrowLeft, arrowRight);
  }
}
