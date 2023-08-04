class Solution {
  public int findTilt(TreeNode root) {
    sum(root);
    return ans;
  }

  private int ans = 0;

  private int sum(TreeNode root) {
    if (root == null)
      return 0;

    final int l = sum(root.left);
    final int r = sum(root.right);
    ans += Math.abs(l - r);
    return root.val + l + r;
  }
}
